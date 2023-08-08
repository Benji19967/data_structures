from typing import Generic, List, TypeVar

T = TypeVar("T")


class Stack(Generic[T]):
    def __init__(self) -> None:
        self._stack: List[T] = []

    def push(self, element: T) -> None:
        self._stack.append(element)

    def pop(self) -> T:
        return self._stack.pop()

    def peek(self) -> T:
        return self._stack[-1]

    def __repr__(self) -> str:
        return repr(self._stack)

    def __len__(self) -> int:
        return len(self._stack)

if __name__ == "__main__":
    stack = Stack[int]()
    stack.push(5)
    stack.push(3)
    print(stack)
    print(stack.peek())
    print(f"Length of Stack: {len(stack)}")
    print(stack.pop())
    print(stack)
