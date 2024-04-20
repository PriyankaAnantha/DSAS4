class Queue():

    def __str__(self):
        return("Queue using List")

    #Constructor function
    def __init__(self):
        self.Q = []

    def ENQUEUE(self, v):
        self.Q.append(v)

    def DEQUEUE(self):
        return(self.Q.pop(0))

    def printQ(self):
        for idx, item in enumerate(self.Q):
            print(idx, item)


if __name__ == '__main__':

    vQueue1= Queue()
    print(vQueue1)


    vQueue1.ENQUEUE(21)
    vQueue1.ENQUEUE(33)
    vQueue1.ENQUEUE(11)
    vQueue1.ENQUEUE(55)

    vQueue1.printQ()

    print("After DEQUEUE")
    vQueue1.DEQUEUE()

    vQueue1.printQ()
