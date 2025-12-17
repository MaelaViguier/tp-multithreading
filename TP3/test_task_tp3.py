import unittest
from task import Task


class TestTaskJSON(unittest.TestCase):
    def test_serialization_and_equality(self):
        a = Task()
        txt = a.to_json()
        b = Task.from_json(txt)
        self.assertEqual(a, b)


if __name__ == "__main__":
    unittest.main()
