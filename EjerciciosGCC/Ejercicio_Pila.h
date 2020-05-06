#include "Ejercicios_Pilas.h"
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
			if(sExpresion[iIndice] == 42 || sExpresion[iIndice] == 43 || sExpresion[iIndice] == 45 || sExpresion[iIndice] == 47)
			{
				if(FnIntPilaVacia(&xPilaOperadores))
					if(FnIntPilaELementos(&xPilaOperandos)>0)
					{
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
			}
			else if(sExpresion[iIndice] >= 48 && sExpresion[iIndice] <= 57)
			{
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
			}
			else
			{
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
		}
		else
			printf("Error. Expresion con Operandos/Operadores de mas\n");
	}		
	return iResult;
						
					
						 
}
