import requests

response = requests.get("http://127.0.0.1:8000/")
print("Response status code:", response.status_code)
print("Response JSON:", response.json())
