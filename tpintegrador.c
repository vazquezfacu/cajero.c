//AUTORES DEL CODIGO: BERNARDI MATIAS, COTELLA JOAQUIN, VAZQUEZ FACUNDO
//ALGORITMO CAJERO
#include <stdio.h>
//Tipo TTarjeta, registro que define los datos asociados a la tarjeta
typedef struct {
	int dni;
	int clave;
	float saldo;
	float montoMax;
}TTarjeta;

TTarjeta t1, t2, t3, t4, tarjeta;
int datosOK;
// Accion que inicializa los datos de las tarjetas
void cargarTarjetas(TTarjeta * tarj1, TTarjeta * tarj2, TTarjeta * tarj3, TTarjeta * tarj4);

// Accion que solicita los datos de ingreso al usuario
void ingresar(int * a, int * b);

// Accion que dado un dni y clave ingresados por el usuario, determina si los datos de 
// acceso son vlidos y ademas determina cual es la tarjeta correspondiente.
void verificarDatosIngreso(int dni, int clave, int * datosOK, TTarjeta * tarjeta);

// Accion que solicita la operacion a realizar
void solicitarOperacion(int * op);

// Accion que muestra al usuario el saldo de la tarjeta y el monto máximo de dinero a extraer.
void consultarSaldo(TTarjeta * tarjeta);

//accion para extraer dinero de la tarjeta
void extraerDinero(float *cant, TTarjeta tarjeta);

//accion para actualizar la clave
void actualizarClave(TTarjeta * tarjeta);

// Accion que podra actualizar el valor correspondiente al máximo importe de extraccion.
void modMaxExtraccion(TTarjeta * tarjeta);


//--------------------------------------------------------ALGORITMO PRINCIPAL
int main(){         
int dni, clave;
TTarjeta tarjeta;
int datosOK;
int operacion;
int finalizar;
float cant;
    
cargarTarjetas(&t1, &t2, &t3, &t4);
ingresar(&dni, &clave);
verificarDatosIngreso(dni, clave, &datosOK, &tarjeta);
  if(datosOK == 1){
    solicitarOperacion(&operacion);
  }
  else{
    printf("Los datos ingresados son incorrectos\n");
  }
  if(operacion == 1){
    consultarSaldo(&tarjeta);
  }
  if(operacion == 2){
    extraerDinero(&cant, tarjeta);
  }
  if(operacion == 3){
    actualizarClave(&tarjeta);
  }
  if(operacion == 4){
	modMaxExtraccion(&tarjeta);
  }
  if(operacion == 5){
    printf("Gracias por confiar en nosotros! Vuelve mas tarde...\n");
  }
  if(operacion >= 6){
  	printf("Se ha ingresado una opcion invalida\n");
  return 0;
  }

}
// Accion que inicializa los datos de las tarjetas
void cargarTarjetas(TTarjeta * tarj1, TTarjeta * tarj2, TTarjeta * tarj3, TTarjeta * tarj4){
  //cargaTarjeta1
  tarj1->dni = 23225226;
  tarj1->clave = 1547;
  tarj1->saldo = 5800;
  tarj1->montoMax = 5000;
  //cargaTarjeta2
  tarj2->dni = 28228331;
  tarj2->clave = 5389;
  tarj2->saldo = 10000;
  tarj2->montoMax = 7000;
  //cargaTarjeta3
  tarj3->dni = 30456189;
  tarj3->clave = 2389;
  tarj3->saldo = 25000;
  tarj3->montoMax = 10000;
  //cargaTarjeta4
  tarj4->dni = 35283281;
  tarj4->clave = 2984;
  tarj4->saldo = 87990;
  tarj4->montoMax = 10000;
}

// Accion que solicita los datos de ingreso al usuario
void ingresar(int * a, int * b){
  printf("Ingrese su dni : ");
  scanf("%d", a);
  printf("Ingrese su clave : ");
  scanf("%d", b);
}

// Accion que dado un dni y clave ingresados por el usuario, determina si los datos de acceso son validos y ademas determina cual es la tarjeta correspondiente.
void verificarDatosIngreso(int dni, int clave, int * datosOK, TTarjeta * tarjeta){	
  if(t1.dni == dni && t1.clave == clave || t2.dni == dni && t2.clave == clave || t3.dni == dni && t3.clave == clave || t4.dni == dni && t4.clave == clave){
    printf("Los datos ingresados son correctos\n");
    *datosOK = 1;
  }else{
    *datosOK = 0;
  }
  if(t1.dni == dni && t1.clave == clave){
    tarjeta->dni = t1.dni;
	tarjeta->clave = t1.clave;
	tarjeta->saldo = t1.saldo;
	tarjeta->montoMax = t1.montoMax;
  } 
  if(t2.dni == dni && t2.clave == clave){
    tarjeta->dni = t2.dni;
	tarjeta->clave = t2.clave;
	tarjeta->saldo = t2.saldo;
	tarjeta->montoMax = t2.montoMax;
  }
  if(t3.dni == dni && t3.clave == clave){
    tarjeta->dni = t3.dni;
	tarjeta->clave = t3.clave;
	tarjeta->saldo = t3.saldo;
	tarjeta->montoMax = t3.montoMax;
  }
  if(t4.dni == dni && t4.clave == clave){
    tarjeta->dni = t4.dni;
	tarjeta->clave = t4.clave;
	tarjeta->saldo = t4.saldo;
	tarjeta->montoMax = t4.montoMax;
  }
    
}


// Accion que solicita la operacion a realizar
void solicitarOperacion(int * op){
  printf("\n\n\tIngrese la operacion que desea realizar\n");
  printf("1. Consultar saldo y limite de extraccion\n");
  printf("2. Extraer dinero\n");
  printf("3. Actualizar clave\n");
  printf("4. Modificar limite de extraccion\n");
  printf("5. Finalizar\n");
  scanf("%d", op);
}

// Accion que muestra al usuario el saldo de la tarjeta y el monto máximo de dinero a extraer.
void consultarSaldo(TTarjeta * tarjeta){
  printf("Su saldo actual es de %2.f pesos y el limite de extraccion de su cuenta es de %2.f pesos", tarjeta->saldo, tarjeta->montoMax);
}

// Accion extraer dinero de la tarjeta
void extraerDinero(float * cant, TTarjeta tarjeta){
  printf("Ingrese la cantidad de dinero a extraer: ");
  scanf("%f",&(*cant));
  if (*cant<=tarjeta.saldo && *cant<=tarjeta.montoMax){
    printf("Puede extraer los $ %2.f solicitados desde la bandeja del cajero" ,*cant);
    (tarjeta.saldo= (tarjeta.saldo-*cant));
  }
  else{
    printf("La cantidad de dinero solicitada a extraer es mas que el saldo disponible en la tarjeta o de su monto maximo actual");
  }
}
// Accion actualizar clave
void actualizarClave(TTarjeta * tarjeta){
  int a;
  int b;
  printf("\n¿Cual quiere que sea su nueva contraseña?\n");
  scanf("%i", &a);
  printf("\nVuelva a ingresar su nueva contraseña\n");
  scanf("%i", &b);
  if(a == b){
    printf("\nSu clave ha sido cambiada con exito\n");
    tarjeta->clave = a;
  }else{
    printf("\nSu clave no es correcta, puede ser que la validacion haya sido incorrecta o no tenga el formato correcto\n");
  }
}

// Accion que podra actualizar el valor correspondiente al máximo importe de extraccion.
void modMaxExtraccion(TTarjeta * tarjeta){
  float aux;
  printf("\nEl importe maximo de extraccion es de %2.f pesos y un saldo existente de %2.f pesos \n",tarjeta->montoMax, tarjeta->saldo);
  printf("Ingrese el valor del nuevo limite de extraccion:\n");
  scanf("%f", &aux);
  if(aux > tarjeta->saldo){
    printf("El saldo de cuenta es menor a lo ingresado\n");
  }else{
    tarjeta->montoMax = aux;
    printf("El nuevo limite de extraccion es de %2.f pesos\n", tarjeta->montoMax);
  }
}
