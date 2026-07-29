# ele procura os arquivos .c e aplica o comando
# compilando todos eles
%.o: %.c
	gcc -c $<

# ele procura os arquivos .o e não encontra
# então ele procurar uma regra que se encaixe
# encontrando a regra logo acima
all: programa.o teste.o
	gcc *.o -o programa

# clean é a regra usada para limpar o projeto
# a ideia é apagar tudo que foi gerado no processo
# de compilação
clean:
	@rm -rf *.o programa