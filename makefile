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

product:
	make cleanFlask; \
	module add python/3.4.3; \
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
	make freshAll; \
	sleep 4 && xterm -hold -e make executeQT & xterm -hold -e python run.py & xterm -hold -e ./ngrok http 5000; \
	pkill python; \

flask3:
	make cleanFlask; \
	make compileQT; \
	module add python/3.4.3; \
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
<<<<<<< HEAD
	make freshAll; \
	sleep 4 && xterm -hold -e make executeQT & xterm -hold -e python run.py & xterm -hold -e ./ngrok http 5000; \
	pkill python; \

executeQT:
	cd QT; \
	qmake-qt5 UI2.pro -spec linux-g++; \
	make; \
	./UI2; \
=======
	# make freshAll; \
	# python run.py & xterm -hold -e ./ngrok http 5000; \
>>>>>>> web_UI

clean:
	rm -rf app.db
	rm -rf __pycache__
	rm -rf db_repository
	rm -rf app/__pycache__
	rm -rf *.pyc
	rm -rf app/*.pyc
	rm -rf app/static/qrcodes/*.jpg

make cleanFlask:
		rm -rf flask; \
