FROM ubuntu
RUN apt-get update && apt-get -y upgrade
RUN apt-get install -y python3-pip

RUN mkdir /opt/flask
WORKDIR /opt/flask
ADD modules.txt /opt/flask
RUN pip3 install --upgrade pip
RUN pip3 install -r modules.txt
ADD . /opt/flask/

WORKDIR /opt/flask/app

EXPOSE 8000
ENTRYPOINT ["python3", "app.py"]
