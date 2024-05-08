from typing import Generic, TypeVar

T = TypeVar("T")


class Heap(Generic[T]):
    """
    Generic implementation of a heap

    """

    def __init__(self):
        pass

    def push(self, element: T):
        """
        Add an element to the heap in O(log n) time

        """
        pass

    def pop(self) -> T:
        """
        Remove and return the min/max element in O(log n) time

        """
        pass

    def peek(self) -> T:
        """
        Get the min/max element in O(1) time

        """
        pass
