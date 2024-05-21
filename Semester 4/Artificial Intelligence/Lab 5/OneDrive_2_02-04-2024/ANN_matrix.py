'''
An example of a simple ANN with 1+2 layers
The implementation uses 2 matrixes in order to memorise the weights.


For a full description:
    
https://towardsdatascience.com/how-to-build-your-own-neural-network-from-scratch-in-python-68998a08e4f6

'''

import numpy as np
import matplotlib as mpl


#the activation function:
def sigmoid(x):
    return 1.0/(1+ np.exp(-x))

#the derivate of te activation function
def sigmoid_derivative(x):
    return x * (1.0 - x)


class NeuralNetwork:
   
    # constructor for this VERY particular network with 2 layers (plus one for input)
    
    def __init__(self, x, y,hidden):
        self.input      = x
        self.weights1   = np.random.rand(self.input.shape[1],hidden) 
        self.weights2   = np.random.rand(hidden,1)                 
        self.y          = y
        self.output     = np.zeros(self.y.shape)
        self.loss       = []


    # the function that computs the output of the network for some input
    def feedforward(self):
        self.layer1 = sigmoid(np.dot(self.input, self.weights1))
        self.output = sigmoid(np.dot(self.layer1, self.weights2))
        


    # the backpropagation algorithm 
    def backprop(self,l_rate):
    # application of the chain rule to find derivative of the    
    #loss function with respect to weights2 and weights1
           d_weights2 = np.dot(self.layer1.T, (2*(self.y - self.output) *
                            sigmoid_derivative(self.output)))
           
           d_weights1 = np.dot(self.input.T,  (np.dot(2*(self.y -
                            self.output) * sigmoid_derivative(self.output),
                            self.weights2.T) *
                             sigmoid_derivative(self.layer1)))
           # update the weights with the derivative (slope) of the loss function
           
           self.weights1 += l_rate * d_weights1
           self.weights2 += l_rate * d_weights2
           self.loss.append(sum((self.y - self.output)**2))


if __name__ == "__main__":
    #X the array of inputs, y the array of outputs, 4 pairs in total 
    X = np.array([[0,0],
                  [0,1],
                  [1,0],
                  [1,1]])
    y = np.array([[0],[1],[1],[0]])
    nn = NeuralNetwork(X,y,2)

    nn.loss=[]
    iterations =[]
    for i in range(4000):
        nn.feedforward()
        nn.backprop(1)
        iterations.append(i)

    print(nn.output)
    mpl.pyplot.plot(iterations, nn.loss, label='loss value vs iteration')
    mpl.pyplot.xlabel('Iterations')
    mpl.pyplot.ylabel('loss function')
    mpl.pyplot.legend()
    mpl.pyplot.show()
    

