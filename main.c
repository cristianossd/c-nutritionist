#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct born {
  int day;
  int month;
  int year;
};

struct person {
  char name[30];
  char sex;
  int age;
  float weight;
  float neck;
  float waist;
  float height;
  float hip;
  float fat;
  float fat_weight;
  float lean_mass_weight;

  struct born born_info;
};

float calculate_man_fat(struct person new_person) {
  float result = 0;

  result = 495/(1.0324 - 0.190077 * (log10(new_person.waist - new_person.neck)) + 0.15456 * (log10(new_person.height))) - 450;
  return result;
}

float calculate_woman_fat(struct person new_person) {
  float result = 0;

  result = 495/(1.29579 - 0.35004 * (log10(new_person.waist + new_person.hip - new_person.neck)) + 0.22100 * (log10(new_person.height))) - 450;
  return result;
}

float calculate_fat_weight(struct person new_person) {
  return (new_person.weight * new_person.fat / 100);
}

float calculate_lean_mass_weight(struct person new_person) {
  return (new_person.weight - new_person.fat_weight);
}

void print_woman_recommendation(struct person new_person) {
  int age = new_person.age;
  float fat = new_person.fat;

  if (age <= 19) {
    if (fat <= 13) {
      printf("Excelente");
    } else if ((fat >= 13.5) && (fat <= 17.5)) {
      printf("Bom");
    } else if ((fat >= 18.0) && (fat <= 21.0)) {
      printf("Médio");
    } else if ((fat >= 22.5) && (fat <= 28.5)) {
      printf("Fraco");
    } else if (fat > 29.0) {
      printf("Muito fraco");
    }
  } else if ((age >= 20) && (age <= 29)) {
    if (fat <= 15) {
      printf("Excelente");
    } else if ((fat >= 15.5) && (fat <= 20.0)) {
      printf("Bom");
    } else if ((fat >= 23.0) && (fat <= 27.0)) {
      printf("Médio");
    } else if ((fat >= 27.5) && (fat <= 31.5)) {
      printf("Fraco");
    } else if (fat > 32.0) {
      printf("Muito fraco");
    }
  } else if ((age >= 30) && (age <= 39)) {
    if (fat <= 17) {
      printf("Excelente");
    } else if ((fat >= 17.5) && (fat <= 24.5)) {
      printf("Bom");
    } else if ((fat >= 24.0) && (fat <= 29.0)) {
      printf("Médio");
    } else if ((fat >= 29.5) && (fat <= 33.5)) {
      printf("Fraco");
    } else if (fat > 34.0) {
      printf("Muito fraco");
    }
  } else if ((age >= 40) && (age <= 49)) {
    if (fat <= 19) {
      printf("Excelente");
    } else if ((fat >= 21.0) && (fat <= 24.0)) {
      printf("Bom");
    } else if ((fat >= 27.0) && (fat <= 32.0)) {
      printf("Médio");
    } else if ((fat >= 32.5) && (fat <= 36.5)) {
      printf("Fraco");
    } else if (fat > 37.0) {
      printf("Muito fraco");
    }
  } else if (age >= 50) {
    if (fat <= 21) {
      printf("Excelente");
    } else if ((fat >= 24.5) && (fat <= 28.0)) {
      printf("Bom");
    } else if ((fat >= 29.0) && (fat <= 34.0)) {
      printf("Médio");
    } else if ((fat >= 34.5) && (fat <= 38.5)) {
      printf("Fraco");
    } else if (fat > 39.0) {
      printf("Muito fraco");
    }
  }

  printf("\n");
}

void print_man_recommendation(struct person new_person) {
  int age = new_person.age;
  float fat = new_person.fat;

  if (age <= 19) {
    if (fat <= 8) {
      printf("Excelente");
    } else if ((fat >= 8.5) && (fat <= 10.5)) {
      printf("Bom");
    } else if ((fat >= 11.0) && (fat <= 13.5)) {
      printf("Médio");
    } else if ((fat >= 14.0) && (fat <= 18.5)) {
      printf("Fraco");
    } else if (fat > 19.0) {
      printf("Muito fraco");
    }
  } else if ((age >= 20) && (age <= 29)) {
    if (fat <= 10) {
      printf("Excelente");
    } else if ((fat >= 10.5) && (fat <= 12.0)) {
      printf("Bom");
    } else if ((fat >= 12.5) && (fat <= 15.0)) {
      printf("Médio");
    } else if ((fat >= 15.5) && (fat <= 19.5)) {
      printf("Fraco");
    } else if (fat > 20.0) {
      printf("Muito fraco");
    }
  } else if ((age >= 30) && (age <= 39)) {
    if (fat <= 11) {
      printf("Excelente");
    } else if ((fat >= 11.5) && (fat <= 12.5)) {
      printf("Bom");
    } else if ((fat >= 15.0) && (fat <= 18.0)) {
      printf("Médio");
    } else if ((fat >= 18.5) && (fat <= 22.5)) {
      printf("Fraco");
    } else if (fat > 23.0) {
      printf("Muito fraco");
    }
  } else if ((age >= 40) && (age <= 49)) {
    if (fat <= 12) {
      printf("Excelente");
    } else if ((fat >= 12.5) && (fat <= 15.0)) {
      printf("Bom");
    } else if ((fat >= 18.0) && (fat <= 22.0)) {
      printf("Médio");
    } else if ((fat >= 22.5) && (fat <= 26.5)) {
      printf("Fraco");
    } else if (fat > 27.0) {
      printf("Muito fraco");
    }
  } else if (age >= 50) {
    if (fat <= 13) {
      printf("Excelente");
    } else if ((fat >= 15.5) && (fat <= 19.0)) {
      printf("Bom");
    } else if ((fat >= 20.0) && (fat <= 24.0)) {
      printf("Médio");
    } else if ((fat >= 25.5) && (fat <= 28.5)) {
      printf("Fraco");
    } else if (fat > 29.0) {
      printf("Muito fraco");
    }
  }

  printf("\n");
}

void print_report(struct person new_person) {
  printf("\n------------------------------------------\n");
  printf("RELATÓRIO\n");
  printf("\n------------------------------------------\n");

  printf("Nome: %s", new_person.name);
  printf("Idade: %d\n", new_person.age);

  printf("Sexo: ");
  if (new_person.sex == 'm') {
    printf("Masculino\n");
  } else {
    printf("Feminino\n");
  }

  printf("Peso: %.2fkg\n", new_person.weight);
  printf("Altura: %.2fcm\n", new_person.height);
  printf("Cintura: %.2fcm\n", new_person.waist);
  printf("Pescoço: %.2fcm\n", new_person.neck);

  if (new_person.sex == 'f')
    printf("Quadril: %.2fcm\n", new_person.hip);

  printf("Porcentagem de Gordura: %.2f\n", new_person.fat);
  printf("Peso gordo: %.2fkg\n", new_person.fat_weight);
  printf("Peso magro: %.2fkg\n", new_person.lean_mass_weight);

  printf("\nSituação nutricional: ");
  if (new_person.sex == 'm') {
    print_man_recommendation(new_person);
  } else {
    print_woman_recommendation(new_person);
  }
  printf("Referência: John Thiel, 1985\n");

}

int main() {
  printf("Bem vindo ao programa de auxílio nutricional\n");

  struct person new_person;
  printf("\nQual seu nome? ");
  fgets(new_person.name, 30, stdin);

  printf("\nOk, %sVamos coletar informações para calcular sua gordura corporal\n", new_person.name);

  printf("\nInicialmente, qual sua data de nascimento? Entre com o dia: ");
  scanf("%d", &new_person.born_info.day);

  if ((new_person.born_info.day < 1) || (new_person.born_info.day > 31)) {
    printf("Você inseriu um dia invalido\n");
    exit(0);
  }

  printf("\nQual o seu mês de nascimento? ");
  scanf("%d", &new_person.born_info.month);

  if ((new_person.born_info.month < 1) || (new_person.born_info.month > 12)) {
    printf("Você inseriu um mês invalido\n");
    exit(0);
  }

  printf("\nQual o seu ano de nascimento? ");
  scanf("%d", &new_person.born_info.year);

  if ((new_person.born_info.year < 1900) || (new_person.born_info.year > 2017)) {
    printf("Você inseriu um ano invalido\n");
    exit(0);
  }

  if (new_person.born_info.year == 2017) {
    printf("Infelizmente, esse programa só calcula a gordura corporal para maiores de um ano");
  }

  new_person.age = 2017 - new_person.born_info.year;
  if ((new_person.born_info.month > 8) || ((new_person.born_info.month == 8) && (new_person.born_info.day == 31))) {
    new_person.age--;
  }

  printf("Sua idade é %d\n", new_person.age);

  printf("Qual seu sexo? (m para masculino, f para feminino) ");
  scanf(" %c", &new_person.sex);

  printf("Qual seu peso? ");
  scanf("%f", &new_person.weight);

  printf("Qual sua altura? ");
  scanf("%f", &new_person.height);

  printf("Qual a medida do seu pescoço? ");
  scanf("%f", &new_person.neck);

  printf("Qual a medida da sua cintura? ");
  scanf("%f", &new_person.waist);

  if (new_person.sex == 'f') {
    printf("Qual a medida do seu quadril? ");
    scanf("%f", &new_person.hip);
  }

  if (new_person.sex == 'm') {
    new_person.fat = calculate_man_fat(new_person);
  } else {
    new_person.fat = calculate_woman_fat(new_person);
  }

  new_person.fat_weight = calculate_fat_weight(new_person);
  new_person.lean_mass_weight = calculate_lean_mass_weight(new_person);

  print_report(new_person);

  return 0;
}
