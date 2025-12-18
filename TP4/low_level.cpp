#include <Eigen/Dense>
#include <cpr/cpr.h>
#include <iostream>
#include <nlohmann/json.hpp>

#include <chrono>

int main() {
  // GET depuis le proxy
  std::cout << "Envoi du GET pour récupérer la tâche...\n";
  auto data = cpr::Get(cpr::Url{"http://localhost:8000"});
  std::cout << "GET reçu, texte JSON reçu : " << data.text.substr(0, 200)
            << "...\n"; // affiche les 200 premiers caractères

  auto j = nlohmann::json::parse(data.text);

  // Extraire A et B
  int size = j["size"];
  Eigen::MatrixXd A(size, size);
  Eigen::VectorXd B(size);
  for (int i = 0; i < size; i++) {
    B(i) = j["b"][i];
    for (int k = 0; k < size; k++) {
      A(i, k) = j["a"][i][k];
    }
  }

  std::cout << "Début du calcul Ax = B pour size = " << size << "\n";

  // Ax = B
  auto start = std::chrono::high_resolution_clock::now();
  Eigen::VectorXd x = A.colPivHouseholderQr().solve(B);
  auto end = std::chrono::high_resolution_clock::now();
  double time_cpp = std::chrono::duration<double>(end - start).count();

  std::cout << "Fin du calcul\n";

  // Affichage du résultat
  std::cout << "Résultat x : [";
  for (int i = 0; i < size; i++) {
    std::cout << x(i) << (i < size - 1 ? ", " : "");
  }
  std::cout << "]\n";
  std::cout << "Temps de calcul C++ : " << time_cpp << " s\n";

  // Envoyer le résultat via POST
  j["x"] = std::vector<double>(x.data(), x.data() + x.size());
  std::string json_result = j.dump();

  auto resp =
      cpr::Post(cpr::Url{"http://localhost:8000"}, cpr::Body{json_result},
                cpr::Header{{"Content-Type", "application/json"}});

  std::cout << "Status POST: " << resp.status_code << "\n";
}
