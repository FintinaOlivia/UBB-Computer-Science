import torch
from torch import nn
import numpy as np
import matplotlib.pyplot as plt

def plot_decision_boundary(model: torch.nn.Module, X: torch.Tensor, y: torch.Tensor) -> None:
    """Plots decision boundaries of a given PyTorch model, in comparison to the ground truth.

    Args:
        model (torch.nn.Module): The PyTorch model to visualize.
        X (torch.Tensor): The input tensor for the model.
        y (torch.Tensor): The ground truth tensor.

    Returns:
        None.

    """
    # Transfer the model and data to CPU
    device = torch.device("cpu")
    model.to(device)
    X, y = X.to(device), y.to(device)

    # Create a grid of prediction boundaries
    x_min, x_max = X[:, 0].min() - 0.1, X[:, 0].max() + 0.1
    y_min, y_max = X[:, 1].min() - 0.1, X[:, 1].max() + 0.1
    xx, yy = np.meshgrid(np.linspace(x_min, x_max, 101), np.linspace(y_min, y_max, 101))

    # Convert the grid to a PyTorch tensor
    X_to_pred_on = torch.from_numpy(np.column_stack((xx.ravel(), yy.ravel()))).float().to(device)

    # Make predictions using the model
    model.eval()
    with torch.no_grad():
        y_logits = model(X_to_pred_on)

    # Determine if this is a binary or multi-class classification problem
    if len(torch.unique(y)) > 2:
        y_pred = torch.softmax(y_logits, dim=1).argmax(dim=1)  # multi-class
    else:
        y_pred = torch.round(torch.sigmoid(y_logits))  # binary

    # Reshape the prediction tensor and plot the decision boundary
    y_pred = y_pred.reshape(xx.shape).detach().numpy()
    plt.contourf(xx, yy, y_pred, cmap=plt.cm.RdYlBu, alpha=0.7)

    # Plot the original data points
    plt.scatter(X[:, 0], X[:, 1], c=y, s=40, cmap=plt.cm.RdYlBu)
    plt.xlim(xx.min(), xx.max())
    plt.ylim(yy.min(), yy.max())