from ds_python.queue import Queue


def test_enqueue():
    q = Queue()
    assert len(q) == 0

    q.enqueue(5)
    assert len(q) == 1
    assert q._queue[0] == 5


def test_dequeue():
    q = Queue()
    assert len(q) == 0

    q.enqueue(7)
    assert len(q) == 1
    assert q._queue[0] == 7

    element = q.dequeue()
    assert element == 7
    assert len(q) == 0
