#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct nasc {
  int dia;
  int mes;
  int ano;
};

struct pessoa {
  char nome[30];
  char sexo;
  int idade;
  float peso;
  float pescoco;
  float cintura;
  float altura;
  float quadril;
  float gordura;
  float gordura_peso;
  float massa_magra_peso;

  struct nasc nasc_info;
};

float calcular_homem_gordura(struct pessoa paciente) {
  float result = 0;

  result = 495/(1.0324 - 0.190077 * (log10(paciente.cintura - paciente.pescoco)) + 0.15456 * (log10(paciente.altura))) - 450;
  return result;
}

float calcular_mulher_gordura(struct pessoa paciente) {
  float result = 0;

  result = 495/(1.29579 - 0.35004 * (log10(paciente.cintura + paciente.quadril - paciente.pescoco)) + 0.22100 * (log10(paciente.altura))) - 450;
  return result;
}

float calcular_gordura_peso(struct pessoa paciente) {
  return (paciente.peso * paciente.gordura / 100);
}

float calcular_massa_magra_peso(struct pessoa paciente) {
  return (paciente.peso - paciente.gordura_peso);
}

void print_mulher_recomendacao(struct pessoa paciente) {
  int idade = paciente.idade;
  float gordura = paciente.gordura;

  if (idade <= 19) {
    if (gordura <= 13) {
      printf("Excelente");
    } else if ((gordura > 13.0) && (gordura <= 17.5)) {
      printf("Bom");
    } else if ((gordura > 17.5) && (gordura <= 21.0)) {
      printf("Médio");
    } else if ((gordura > 21.0) && (gordura <= 28.5)) {
      printf("Fraco");
    } else if (gordura > 28.5) {
      printf("Muito fraco");
    }
  } else if ((idade >= 20) && (idade <= 29)) {
    if (gordura <= 15) {
      printf("Excelente");
    } else if ((gordura > 15.0) && (gordura <= 20.0)) {
      printf("Bom");
    } else if ((gordura > 20.0) && (gordura <= 27.0)) {
      printf("Médio");
    } else if ((gordura > 27.0) && (gordura <= 31.5)) {
      printf("Fraco");
    } else if (gordura > 31.5) {
      printf("Muito fraco");
    }
  } else if ((idade >= 30) && (idade <= 39)) {
    if (gordura <= 17) {
      printf("Excelente");
    } else if ((gordura > 17.0) && (gordura <= 24.5)) {
      printf("Bom");
    } else if ((gordura > 24.5) && (gordura <= 29.0)) {
      printf("Médio");
    } else if ((gordura > 29.0) && (gordura <= 33.5)) {
      printf("Fraco");
    } else if (gordura > 33.5) {
      printf("Muito fraco");
    }
  } else if ((idade >= 40) && (idade <= 49)) {
    if (gordura <= 19) {
      printf("Excelente");
    } else if ((gordura > 19.9) && (gordura <= 24.0)) {
      printf("Bom");
    } else if ((gordura > 24.0) && (gordura <= 32.0)) {
      printf("Médio");
    } else if ((gordura > 32.0) && (gordura <= 36.5)) {
      printf("Fraco");
    } else if (gordura > 36.5) {
      printf("Muito fraco");
    }
  } else if (idade >= 50) {
    if (gordura <= 21) {
      printf("Excelente");
    } else if ((gordura > 21.0) && (gordura <= 28.0)) {
      printf("Bom");
    } else if ((gordura > 28.0) && (gordura <= 34.0)) {
      printf("Médio");
    } else if ((gordura > 34.0) && (gordura <= 38.5)) {
      printf("Fraco");
    } else if (gordura > 38.5) {
      printf("Muito fraco");
    }
  }

  printf("\n");
}

void print_homem_recomendacao(struct pessoa paciente) {
  int idade = paciente.idade;
  float gordura = paciente.gordura;

  if (idade <= 19) {
    if (gordura <= 8) {
      printf("Excelente");
    } else if ((gordura > 8.0) && (gordura <= 10.5)) {
      printf("Bom");
    } else if ((gordura > 10.5) && (gordura <= 13.5)) {
      printf("Médio");
    } else if ((gordura > 13.5) && (gordura <= 18.5)) {
      printf("Fraco");
    } else if (gordura > 18.5) {
      printf("Muito fraco");
    }
  } else if ((idade >= 20) && (idade <= 29)) {
    if (gordura <= 10) {
      printf("Excelente");
    } else if ((gordura > 10.0) && (gordura <= 12.0)) {
      printf("Bom");
    } else if ((gordura > 12.0) && (gordura <= 15.0)) {
      printf("Médio");
    } else if ((gordura > 15.0) && (gordura <= 19.5)) {
      printf("Fraco");
    } else if (gordura > 19.5) {
      printf("Muito fraco");
    }
  } else if ((idade >= 30) && (idade <= 39)) {
    if (gordura <= 11) {
      printf("Excelente");
    } else if ((gordura > 11.0) && (gordura <= 12.5)) {
      printf("Bom");
    } else if ((gordura > 12.5) && (gordura <= 18.0)) {
      printf("Médio");
    } else if ((gordura > 18.0) && (gordura <= 22.5)) {
      printf("Fraco");
    } else if (gordura > 22.5) {
      printf("Muito fraco");
    }
  } else if ((idade >= 40) && (idade <= 49)) {
    if (gordura <= 12) {
      printf("Excelente");
    } else if ((gordura > 12.0) && (gordura <= 15.0)) {
      printf("Bom");
    } else if ((gordura > 15.0) && (gordura <= 22.0)) {
      printf("Médio");
    } else if ((gordura > 22.0) && (gordura <= 26.5)) {
      printf("Fraco");
    } else if (gordura > 26.5) {
      printf("Muito fraco");
    }
  } else if (idade >= 50) {
    if (gordura <= 13) {
      printf("Excelente");
    } else if ((gordura > 13.0) && (gordura <= 19.0)) {
      printf("Bom");
    } else if ((gordura > 19.0) && (gordura <= 24.0)) {
      printf("Médio");
    } else if ((gordura > 24.0) && (gordura <= 28.5)) {
      printf("Fraco");
    } else if (gordura > 28.5) {
      printf("Muito fraco");
    }
  }

  printf("\n");
}

void print_report(struct pessoa paciente) {
  printf("\n------------------------------------------\n");
  printf("RELATÓRIO\n");
  printf("\n------------------------------------------\n");

  printf("Nome: %s", paciente.nome);
  printf("Idade: %d\n", paciente.idade);

  printf("sexoo: ");
  if (paciente.sexo == 'm') {
    printf("Masculino\n");
  } else {
    printf("Feminino\n");
  }

  printf("Peso: %.2fkg\n", paciente.peso);
  printf("Altura: %.2fcm\n", paciente.altura);
  printf("Cintura: %.2fcm\n", paciente.cintura);
  printf("Pescoço: %.2fcm\n", paciente.pescoco);

  if (paciente.sexo == 'f')
    printf("Quadril: %.2fcm\n", paciente.quadril);

  printf("Porcentidadem de Gordura: %.2f\n", paciente.gordura);
  printf("Peso gordo: %.2fkg\n", paciente.gordura_peso);
  printf("Peso magro: %.2fkg\n", paciente.massa_magra_peso);

  printf("\nSituação nutricional: ");
  if (paciente.sexo == 'm') {
    print_homem_recomendacao(paciente);
  } else {
    print_mulher_recomendacao(paciente);
  }
  printf("Referência: John Thiel, 1985\n");

}

int main() {
  printf("Bem vindo ao programa de auxílio nutricional\n");

  struct pessoa paciente;
  printf("\nQual seu nome? ");
  fgets(paciente.nome, 30, stdin);

  printf("\nOk, %sVamos coletar informações para calcular sua gordura corporal\n", paciente.nome);

  printf("\nInicialmente, qual sua data de nascimento? Entre com o dia: ");
  scanf("%d", &paciente.nasc_info.dia);

  if ((paciente.nasc_info.dia < 1) || (paciente.nasc_info.dia > 31)) {
    printf("Você inseriu um dia invalido\n");
    exit(0);
  }

  printf("\nQual o seu mês de nascimento? ");
  scanf("%d", &paciente.nasc_info.mes);

  if ((paciente.nasc_info.mes < 1) || (paciente.nasc_info.mes > 12)) {
    printf("Você inseriu um mês invalido\n");
    exit(0);
  }

  printf("\nQual o seu ano de nascimento? ");
  scanf("%d", &paciente.nasc_info.ano);

  if ((paciente.nasc_info.ano < 1900) || (paciente.nasc_info.ano > 2017)) {
    printf("Você inseriu um ano invalido\n");
    exit(0);
  }

  if (paciente.nasc_info.ano == 2017) {
    printf("Infelizmente, esse programa só calcula a gordura corporal para maiores de um ano");
  }

  paciente.idade = 2017 - paciente.nasc_info.ano;
  if ((paciente.nasc_info.mes > 8) || ((paciente.nasc_info.mes == 8) && (paciente.nasc_info.dia == 31))) {
    paciente.idade--;
  }

  printf("Sua idade é %d\n", paciente.idade);

  printf("Qual seu sexoo? (m para masculino, f para feminino) ");
  scanf(" %c", &paciente.sexo);

  printf("Qual seu peso? ");
  scanf("%f", &paciente.peso);

  printf("Qual sua altura? ");
  scanf("%f", &paciente.altura);

  printf("Qual a medida do seu pescoço? ");
  scanf("%f", &paciente.pescoco);

  printf("Qual a medida da sua cintura? ");
  scanf("%f", &paciente.cintura);

  if (paciente.sexo == 'f') {
    printf("Qual a medida do seu quadril? ");
    scanf("%f", &paciente.quadril);
  }

  if (paciente.sexo == 'm') {
    paciente.gordura = calcular_homem_gordura(paciente);
  } else {
    paciente.gordura = calcular_mulher_gordura(paciente);
  }

  paciente.gordura_peso = calcular_gordura_peso(paciente);
  paciente.massa_magra_peso = calcular_massa_magra_peso(paciente);

  print_report(paciente);

  return 0;
}
