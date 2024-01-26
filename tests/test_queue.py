from ds.queue import Queue


def test_enqueue():
    q = Queue()
    assert len(q) == 0

    q.enqueue(5)
    assert len(q) == 1
    assert q._queue[0] == 5
