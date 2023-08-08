from typing import Generic, List, TypeVar

T = TypeVar("T")


class Queue(Generic[T]):
    def __init__(self) -> None:
        self._queue: List[T] = []

    def push(self, element: T) -> None:
        self._queue.append(element)

    def pop(self) -> T:
        """
        This is inefficient as the entire queue needs to be copied 
        on every pop: O(N)
        """
        element = self._queue[0]
        self._queue = self._queue[1:]
        return element

    def peek(self) -> T:
        return self._queue[0]

    def __repr__(self) -> str:
        return repr(self._queue)

    def __len__(self) -> int:
        return len(self._queue)

if __name__ == "__main__":
    queue = Queue[int]()
    queue.push(5)
    queue.push(3)
    print(queue)
    print(queue.peek())
    print(f"Length of Queue: {len(queue)}")
    print(queue.pop())
    print(queue)

