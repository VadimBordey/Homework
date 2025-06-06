from fastapi import FastAPI, Depends, HTTPException
from fastapi.security import HTTPBasic, HTTPBasicCredentials
import requests
import secrets
import os
from dotenv import load_dotenv

load_dotenv()

app = FastAPI()
security = HTTPBasic()

USERNAME = os.getenv("USERNAME")
PASSWORD = os.getenv("PASSWORD")

def check_auth(credentials: HTTPBasicCredentials = Depends(security)):
    correct_username = secrets.compare_digest(credentials.username, USERNAME)
    correct_password = secrets.compare_digest(credentials.password, PASSWORD)
    if not (correct_username and correct_password):
        raise HTTPException(status_code=401, detail="Unauthorized")

def weather_to_emoji(description: str) -> str:
    description = description.lower()
    if "rain" in description or "drizzle" in description:
        return "🌧️"
    elif "cloud" in description:
        return "☁️"
    elif "sun" in description or "clear" in description:
        return "☀️"
    elif "snow" in description:
        return "❄️"
    elif "storm" in description:
        return "⛈️"
    else:
        return "🌈"

@app.get("/weather")
def get_weather(city: str = "Kyiv", _: HTTPBasicCredentials = Depends(check_auth)):
    url = f"https://wttr.in/{city}?format=j1"

    try:
        response = requests.get(url)
        response.raise_for_status()
        data = response.json()

        current = data["current_condition"][0]

        temp = current["temp_C"]
        humidity = current["humidity"]
        description = current["weatherDesc"][0]["value"]
        emoji = weather_to_emoji(description)

        return {
            "city": city,
            "temperature": f"{temp}°C",
            "condition": description,
            "humidity": f"{humidity}%",
            "emoji": emoji
        }

    except Exception as e:
        raise HTTPException(status_code=500, detail=f"Weather API error: {str(e)}")
