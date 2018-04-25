db:
	python3 db_create.py

pop:
	python3 populatingDatabase.py

mig:
	python3 db_migrate.py

freshAll:
	clear
	make clean
	python3 db_create.py
	python3 populatingDatabase.py

oldAll:
	python3 db_migrate.py
	python3 populatingDatabase.py

flask:
	virtualenv flask; \
	source flask/bin/activate; \
	flask/bin/pip install flask; \
	flask/bin/pip install flask-login; \
	flask/bin/pip install flask-mail; \
	flask/bin/pip install flask-sqlalchemy; \
	flask/bin/pip install sqlalchemy-migrate; \
	flask/bin/pip install flask-whooshalchemy; \
	flask/bin/pip install flask-wtf; \
	flask/bin/pip install flask-babel; \
	flask/bin/pip install coverage; \
	flask/bin/pip install Pillow; \
	flask/bin/pip install qrcode; \

flask3:
	virtualenv -p python3 flask; \
	source flask/bin/activate; \
	flask/bin/pip install flask; \
	flask/bin/pip install flask-login; \
	flask/bin/pip install flask-mail; \
	flask/bin/pip install flask-sqlalchemy; \
	flask/bin/pip install sqlalchemy-migrate; \
	flask/bin/pip install flask-whooshalchemy; \
	flask/bin/pip install flask-wtf; \
	flask/bin/pip install flask-babel; \
	flask/bin/pip install coverage; \

clean:
	rm -rf app.db
	rm -rf __pycache__
	rm -rf db_repository
	rm -rf app/__pycache__
	rm -rf *.pyc
	rm -rf app/*.pyc
	rm -rf app/static/qrcodes/*.jpg

cleanFlask:
	rm -rf flask/
