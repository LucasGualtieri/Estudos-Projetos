#include <stdio.h>

typedef enum {
	CHEESE, VEGGIE
} PizzaType;

/*typedef enum {*/
/*	CHEESE*/
/*} Hamburger;*/

typedef struct {
	char* type;
} Pizza;

Pizza createPizza(PizzaType type) {

	Pizza pizza = {
		.type = "padrão"
	};

	if (CHEESE == type) {
		pizza.type = "cheese";
	}

	else if (VEGGIE == type) {
		pizza.type = "veggie";
	}

	return pizza;
}

int main() {

	Pizza pizza = createPizza((PizzaType)2);

	printf("Pizza type: %s\n", pizza.type);

	return 0;
}

