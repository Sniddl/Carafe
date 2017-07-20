from flask import Flask
app = Flask(__name__)
app.debug = True

@app.route("/home")
def hello():
   return "Hello World from Flask using ad 3.5"

if __name__ == "__main__":
   app.run(host='0.0.0.0', debug=True, port=80)
