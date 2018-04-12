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

clean:
	rm -rf app.db
	rm -rf __pycache__
	rm -rf db_repository
	rm -rf app/__pycache__
