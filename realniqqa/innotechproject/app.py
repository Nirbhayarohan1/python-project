from flask import Flask, render_template, request, json
import pandas as pd
import json
from forecast_model import forecast

app = Flask(__name__)

# Home route
@app.route('/')
def index():
    return render_template('index.html')

# Upload data
@app.route('/upload', methods=['POST'])
def upload_data():
    file = request.files['file']
    data = pd.read_csv(file)
    data.to_csv('data/sample_data.csv', index=False)  # Save uploaded file
    return json({'message': 'File uploaded successfully!'})

# Display data visualization
@app.route('/dashboard', methods=['GET'])
def dashboard():
    data = pd.read_csv('data/sample_data.csv')
    chart_data = data.to_dict(orient='records')
    return render_template('dashboard.html', data=json.dumps(chart_data))

# Forecast route
@app.route('/forecast', methods=['POST'])
def get_forecast():
    data = pd.read_csv('data/sample_data.csv')
    forecast_result = forecast(data)
    return json(forecast_result)

if __name__ == '__main__':
    app.run(debug=True)