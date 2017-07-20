from flask import Flask, render_template
import env
from kernel import *

app = Flask(__name__)


@app.route('/')
def index():
    return view('home.html', posts=Posts())

def posts():
    return view('posts')

if __name__ == '__main__':
    app.run(debug=env.debug, host=env.host, port=env.port)
