import pandas as pd
from sklearn.linear_model import LinearRegression
import numpy as np

def forecast(data):
    """
    Forecast food supply trends based on historical data.
    """
    result = {}
    for commodity in data.columns[1:]:
        # Extract years and values
        years = np.array(range(len(data))).reshape(-1, 1)
        values = data[commodity].values.reshape(-1, 1)
        
        # Train Linear Regression Model
        model = LinearRegression()
        model.fit(years, values)
        next_years = np.array(range(len(data), len(data) + 5)).reshape(-1, 1)
        predictions = model.predict(next_years)
        
        # Save results
        result[commodity] = predictions.flatten().tolist()
    return result
