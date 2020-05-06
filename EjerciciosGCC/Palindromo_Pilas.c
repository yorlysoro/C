#include "Pilas_Palindromo.h"
#include <string.h>

int FnIntPalindromo(char *sCadena)
{
	pila xPila;
	char sPalindromo[30];
	int cIndice;
	
	SbPilaInicializa(&xPila);
	
	for(cIndice=0;cIndice<strlen(sCadena);cIndice++)
		SbPilaPush(&xPila,sCadena[cIndice]);
	
	cIndice = 0;
	
	while(!FnIntPilaVacia(&xPila))
		sPalindromo[cIndice++] = FnIntPilaPop(&xPila);
	 
	 sPalindromo[cIndice]='\0';
	 
	 if(strcmp(sCadena,sPalindromo)==0)
		return TRUE;
	else
		return FALSE;
	
}


char *FnStrInverso(char *sCadena)
{
	pila xPila;
	
	static char sResult[30];
	int cIndice;
	
	SbPilaInicializa(&xPila);
	
	for(cIndice=0;cIndice<strlen(sCadena);cIndice++)
		SbPilaPush(&xPila,sCadena[cIndice]);
	
	cIndice = 0;
	
	while(!FnIntPilaVacia(&xPila))
		sResult[cIndice++] = FnIntPilaPop(&xPila);
	
	 sResult[cIndice]='\0';
	 
	 return (sResult);
}

int FnIntExpresionEvalua(char *sExpresion)
{
	pila xPilaOperandos;
	pila xPilaOperadores;
	
	SbPilaInicializa(&xPilaOperandos);
	SbPilaInicializa(&xPilaOperadores);
	
	int iIndice;
	
	int iResult=0;
	
	char cOperador;
	
	int cOperando;
	
	printf("Analizando Expresion...\n");
	
	for(iIndice=0;iIndice<strlen(sExpresion); iIndice++)
	{
		if(sExpresion[iIndice] != ESPACIO_EN_BLANCO)
		{
			switch(sExpresion[iIndice])
			{
				case 43:
				case 45:
				case 42:
				case 47:
					if(FnIntPilaVacia(&xPilaOperadores))
						if(FnIntPilaELementos(&xPilaOperandos)>0)
						{
							printf("%c es un operador; es agrega a la fila de operdores\n", sExpresion[iIndice] );
							SbPilaPush(&xPilaOperadores,sExpresion[iIndice]);
						}
						else
						{
							printf("Error. Operador sin operando Previo: %c", sExpresion[iIndice]);
							iResult = -1;
						}
					else
					{
						printf("Error. Exceso de operadores: %c\n", sExpresion[iIndice] );
						iResult = -1;
					}
				break;
				case 48:
				case 49:
				case 50:
				case 51:
				case 52:
				case 53:
				case 54:
				case 55:
				case 56:
				case 57:
					if(FnIntPilaVacia(&xPilaOperadores))
						if(FnIntPilaVacia(&xPilaOperandos))
							SbPilaPush(&xPilaOperandos,sExpresion[iIndice]-48);
						else
						{
							printf("Error. Exceso de Operandos: %c\n", sExpresion[iIndice]);
							iResult = -1;
						}
					else
					{
						cOperador=FnIntPilaPop(&xPilaOperadores);
						cOperando=FnIntPilaPop(&xPilaOperandos);
						if(cOperador == '+')
							iResult = cOperando + (sExpresion[iIndice]-48);
						else if(cOperador == '-')
							iResult = cOperando - (sExpresion[iIndice]-48);
						else if(cOperador == '*')
							iResult = cOperando * (sExpresion[iIndice]-48);
						else
							iResult = cOperando / (sExpresion[iIndice]-48);
						SbPilaPush(&xPilaOperandos,iResult);
						iResult=0;
					}
					break;
				default:
				printf("Error. Caracter no reconocido: %c\n", sExpresion[iIndice]);
				iResult = -1;
				break;
			}
		}//If del Espacio en Blanco
		if(iResult == -1)
		break;
	}//Ciclo For
	if(iResult!=-1)
	{
		if(FnIntPilaELementos(&xPilaOperandos) == 1 && FnIntPilaVacia(&xPilaOperadores))
		{
			iResult = FnIntPilaPop(&xPilaOperandos);
			printf("El resultado de la expresion %s es %d \n", sExpresion, iResult);
		}
		else
			printf("Error. Expresion con Operandos/Operadores de mas\n");
	}		
	return iResult;
						
					
						 
}

int main(void)
{
	//char sCadena[30];
	
	//strcpy(sCadena, "sevansusnaves");
	
	//if(FnIntPalindromo(sCadena) == TRUE)
	//printf("La cadena %s si es un palindromo\n", sCadena);
	//else
	//printf("La cadena %s no es un palindromo\n", sCadena);
	
	//printf("La cadena inversa de JAORSOFTWARE es: %s\n", FnStrInverso("JOARSOFTWARE"));
	FnIntExpresionEvalua("5+5");
	return 0;
	
}
