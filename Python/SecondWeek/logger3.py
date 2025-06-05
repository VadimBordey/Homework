import sys
from datetime import datetime
from abc import ABC, abstractmethod

class Formatter(ABC):
    @abstractmethod
    def format(self, message: str) -> str:
        pass

class TimeFormatter(Formatter):
    def init(self, time_format='%Y-%m-%d %H:%M:%S'):
        self.time_format = time_format

    def format(self, message: str) -> str:
        now = datetime.now().strftime(self.time_format)
        return f"[{now}] {message}"

class Handler(ABC):
    @abstractmethod
    def handle(self, formatted_message: str):
        pass

class StreamHandler(Handler):
    def init(self, stream=sys.stderr):
        self.stream = stream

    def handle(self, formatted_message: str):
        print(formatted_message, file=self.stream)

class Logger:
    def init(self, formatter: Formatter):
        self.formatter = formatter
        self.handlers = []

    def add_handler(self, handler: Handler):
        self.handlers.append(handler)

    def log(self, message: str):
        formatted_message = self.formatter.format(message)
        for handler in self.handlers:
            handler.handle(formatted_message)
