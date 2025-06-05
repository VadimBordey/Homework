import sys
from datetime import datetime

class Logger:
    def init(self, out_stream=sys.stderr, time_formatter='%Y-%m-%d %H:%M:%S'):
        self.out_stream = out_stream
        self.time_formatter = time_formatter

    def log(self, message):
        now = datetime.now().strftime(self.time_formatter)
        print(f"[{now}] {message}", file=self.out_stream)
