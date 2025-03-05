project_name := main
uvproj_path := .
.PHONY: default build cformat format clean flash debug assets

build:
	@echo 【START】----- UV build -----
	@g++ main.cpp -o main; .\main.exe
	@echo 【 END 】----- UV build -----




format:
	./utils_bin/astyle.exe --project="./utils_bin/.astylerc" -r **.c,**.h --ignore-exclude-errors --exclude=_build --exclude=utils_bin --exclude=dist --exclude=utils -v -Q

assets:
	@echo Create Assets
	./utils_bin/p2a-win-amd64.exe -in ./moudle/ui -out ./moudle/image

