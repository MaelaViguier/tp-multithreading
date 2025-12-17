# test_task.py
import unittest
import numpy as np
from task import Task


class TestTask(unittest.TestCase):
    def test_solution_accuracy(self):
        task = Task(size=100)
        task.work()
        np.testing.assert_allclose(task.a @ task.x, task.b, rtol=1e-7, atol=0)


if __name__ == "__main__":
    unittest.main()
