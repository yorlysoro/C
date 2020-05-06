#include <stdio.h>
//#include <conio.h>

float monto,montoventa,pagoefectivo,pagodebito,pagocredito;
int num;
char seguir,pago,Efectivo,Debito,Credito;
int main ()

{

monto=0;


  do
   {
  	 printf ("Especifique el monto de la venta: ");
  	 scanf ("%f",&montoventa);
  	
  	 printf ("Como cancelara la venta? (Efectivo/Debito/Credito): ");
  	 scanf ("%s",&pago);
  	
  	 if ( pago == Efectivo )
  	 {
  	 scanf ("%f",&pagoefectivo);
     }
  	 if ( pago == Debito )
  	 {
	 scanf ("%f",&pagodebito);
     }
	 if ( pago == Credito )
	 {
  	 scanf ("%f",&pagocredito);
     }
    
  	monto=monto+montoventa;
  	
  	printf ("Ingresar otro producto vendido? (s/n): ");
  	scanf( "%s", &seguir);
    } while ( seguir != 'n' );
    
    
    
    printf ("El monto de la venta total es: %f", monto);
    
}
