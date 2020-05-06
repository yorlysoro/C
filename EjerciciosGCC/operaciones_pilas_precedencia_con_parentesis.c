#include <stdio.h>
#include "Ejercicios_Pilas.h"
#include <string.h>
#include <math.h>
int FnIntDigitosEs(char cCaracter);
int FnIntOperadorEs(char cCaracter);
int FnIntMayorPrioridad(char cOperardor1, char cOperardor2);
int FnIntExpresionEvaluaPrioridad(char *sExpresion);

int main(void)
{
	//printf("Evaluando Prioridad entre operadores...\n");
	//printf("Tiene nayor prioridad + que + => %d\n", FnIntMayorPrioridad('+', '+'));
	//printf("Tiene nayor prioridad + que - => %d\n", FnIntMayorPrioridad('+', '-'));
	//printf("Tiene nayor prioridad + que * => %d\n", FnIntMayorPrioridad('+', '*'));
	//printf("Tiene nayor prioridad + que / => %d\n", FnIntMayorPrioridad('+', '/'));
	//printf("Tiene nayor prioridad + que e => %d\n", FnIntMayorPrioridad('+', 'e'));
	//printf("Tiene nayor prioridad - que + => %d\n", FnIntMayorPrioridad('-', '+'));
	//printf("Tiene nayor prioridad - que - => %d\n", FnIntMayorPrioridad('-', '*'));
	//printf("Tiene nayor prioridad - que * => %d\n", FnIntMayorPrioridad('-', '*'));
	//printf("Tiene nayor prioridad - que / => %d\n", FnIntMayorPrioridad('-', '/'));
	//printf("Tiene nayor prioridad - que e => %d\n", FnIntMayorPrioridad('-', 'e'));
	//printf("Tiene nayor prioridad * que + => %d\n", FnIntMayorPrioridad('*', '+'));
	//printf("Tiene nayor prioridad * que - => %d\n", FnIntMayorPrioridad('*', '-'));
	//printf("Tiene nayor prioridad * que * => %d\n", FnIntMayorPrioridad('*', '*'));
	//printf("Tiene nayor prioridad * que / => %d\n", FnIntMayorPrioridad('*', '/'));
	//printf("Tiene nayor prioridad * que e => %d\n", FnIntMayorPrioridad('*', 'e'));
	//printf("Tiene nayor prioridad / que + => %d\n", FnIntMayorPrioridad('/', '+'));
	//printf("Tiene nayor prioridad / que - => %d\n", FnIntMayorPrioridad('/', '-'));
	//printf("Tiene nayor prioridad / que * => %d\n", FnIntMayorPrioridad('/', '*'));
	//printf("Tiene nayor prioridad / que / => %d\n", FnIntMayorPrioridad('/', '/'));
	//printf("Tiene nayor prioridad / que e => %d\n", FnIntMayorPrioridad('/', 'e'));
	//printf("Tiene nayor prioridad e que + => %d\n", FnIntMayorPrioridad('e', '+'));
	//printf("Tiene nayor prioridad e que - => %d\n", FnIntMayorPrioridad('e', '-'));
	//printf("Tiene nayor prioridad e que * => %d\n", FnIntMayorPrioridad('e', '*'));
	//printf("Tiene nayor prioridad e que / => %d\n", FnIntMayorPrioridad('e', '/'));
	//printf("Tiene nayor prioridad e que e => %d\n", FnIntMayorPrioridad('e', 'e'));
	
	FnIntExpresionEvaluaPrioridad("(5+6)*4e2");
	return 0;
	
}

int FnIntDigitosEs(char cCaracter)
{
	if(cCaracter>47 && cCaracter<58)
		return TRUE;
	else
		return FALSE;
}

int FnIntOperadorEs(char cCaracter)
{
	int iResult = FALSE;
	
	switch(cCaracter)
	{
		case 43:
		case 45:
		case 42:
		case 47:
		case 'e':
			iResult = TRUE;
			break;
	}
	return (iResult);
}

int FnIntMayorPrioridad(char cOperardor1, char cOperardor2)
{
	int iResult;
	
	switch(cOperardor1)
	{
		case '(': iResult = FALSE;
			break;
		case 43:
		case 45:if(cOperardor2 == '+' || cOperardor2 == '-')
					iResult = TRUE;
				else 
					iResult = FALSE;
			break;
			
		case 42:
		case 47:if (cOperardor2=='e')
					iResult = FALSE;
				else
					iResult = TRUE;
			break;
		case 'e': iResult = TRUE;
			break;
	}
	return iResult;	
}

int FnIntExpresionEvaluaPrioridad(char * sExpresion)
{
	pila xPilaOperandos;
	pila xPilaOperadores;
	
	SbPilaInicializa(&xPilaOperandos);
	SbPilaInicializa(&xPilaOperadores);
	
	int iIndice;
	int iResult = 0;
	char cOperador;
	int cOperando, cOperando2;
	
	printf("Analizando la expresion ...\n");
	
	for(iIndice=0; iIndice<strlen(sExpresion); iIndice++)
	{
		if(sExpresion[iIndice] != ESPACIO_EN_BLANCO)
		{
			switch(sExpresion[iIndice])
			{
				case 40:
					if(FnIntPilaVacia(&xPilaOperadores) && !FnIntPilaVacia(&xPilaOperandos))
					{
						printf("Error. Falta operador antes de: %c\n", sExpresion[iIndice] );
					}
					else
						SbPilaPush(&xPilaOperadores,sExpresion[iIndice]);
					break;
				case 41:
					while(FnIntPilaCima(&xPilaOperadores) != '(' && !FnIntPilaVacia(&xPilaOperadores))
					{
						cOperador = FnIntPilaPop(&xPilaOperadores);
						if(!FnIntPilaVacia(&xPilaOperandos))
							cOperando2=FnIntPilaPop(&xPilaOperandos);
						else
						{
							printf("Error. Falta operando 2 para operacion: %c\n", cOperador);
							iResult=-1;
							break;
						}
						
						if(!FnIntPilaVacia(&xPilaOperandos))
							cOperando=FnIntPilaPop(&xPilaOperandos);
						else
						{
							printf("Error. Falta operando 1 para operacion:%c\n", cOperador);
							iResult = -1;
							break;
						}
						
						if(cOperador == '+')
						iResult = cOperando + cOperando2;
						else if(cOperador == '-')
						iResult = cOperando - cOperando2;
						else if(cOperador == '*')
						iResult = cOperando * cOperando2;
						else if(cOperador == '/')
						iResult = cOperando / cOperando2;
						else 
						iResult = pow(cOperando,cOperando2);
						
						printf("Se realizo la operacion 1: %d %c %d = %d\n", cOperando2, cOperador, cOperando, iResult);
						SbPilaPush(&xPilaOperandos,iResult);
						iResult = 0;
					}
					if(iResult != -1)
					{
						if(FnIntPilaVacia(&xPilaOperadores))
						{
							printf("Error. No es encontro un ( necesario\n");
							iResult = 0;
						}
						else
						{
							FnIntPilaPop(&xPilaOperadores);
							
							if(iIndice < strlen(sExpresion)-1)
							{
								if(FnIntDigitosEs(sExpresion[iIndice+1]))
								{
									printf("Error. Falta un operador antes de %c\n", sExpresion[iIndice+1]);
									iResult=-1;
								}
								else
									if(FnIntOperadorEs(sExpresion[iIndice+1]))
										if(FnIntPilaVacia(&xPilaOperadores))
										{
											SbPilaPush(&xPilaOperadores,sExpresion[++iIndice]);
										}
										else
											if(FnIntMayorPrioridad(FnIntPilaCima(&xPilaOperadores),sExpresion[iIndice+1]))
											{
												cOperador = FnIntPilaPop(&xPilaOperadores);
												cOperando = FnIntPilaPop(&xPilaOperandos);
												cOperando2 = FnIntPilaPop(&xPilaOperandos);
												
												if(cOperador== '+')
													iResult = cOperando2 + cOperando;
												else
													if(cOperador == '-')
														iResult = cOperando2 - cOperando;
													else
														if(cOperador == '*')
															iResult = cOperando2 * cOperando;
														else
															if(cOperador == '/')
																iResult = cOperando2 / cOperando;
															else
																iResult = pow(cOperando2,cOperando);
												printf("Se realizo la operacion: %d %c %d = %d\n", cOperando, cOperador, cOperando2, iResult);
												
												SbPilaPush(&xPilaOperandos,iResult);
												iResult = 0;
											}
											else
											{
												SbPilaPush(&xPilaOperadores,sExpresion[++iIndice]);
											}
											else
											if(sExpresion[iIndice+1] == ')')
											
												if(sExpresion[iIndice+1]== '(')
												{
													printf("Error. Se necesita un operardor antes de un (\n");
													iResult=-1;
												}
												else
												{
													printf("Error. Caracter no Reconocido: %c\n", sExpresion[iIndice+1]);
													iResult = -1;
												}
										}
									}
								}
							break;
						
				case 43:
				case 45:
				case 42:
				case 47:
				case 'e':
					if(FnIntPilaVacia(&xPilaOperadores))
						if(FnIntPilaELementos(&xPilaOperandos) > 0)
						{
							printf("%c es un Operador; se agregara a la Pila de operadores\n", sExpresion[iIndice]);
							SbPilaPush(&xPilaOperadores, sExpresion[iIndice]);
						}
						else
						{
							printf("Error. Operador sin Operando Previo: %c\n", sExpresion[iIndice]);
							iResult=-1;
						}
					else
						if (FnIntPilaCima(&xPilaOperadores) != '(')
						{
							printf("Error. Exceso de operadores %c\n", sExpresion[iIndice]);
							iResult=-1;
						}
					else
					{
						printf("%c es un operador, se agrega a la pila de operadores\n", sExpresion[iIndice]);
						SbPilaPush(&xPilaOperadores, sExpresion[iIndice]);
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
							iResult=-1;
						}
					else
					{
						if(iIndice == strlen(sExpresion)-1)
						{
							cOperador = FnIntPilaPop(&xPilaOperadores);
							cOperando = FnIntPilaPop(&xPilaOperandos);
							if(cOperador=='+')
								iResult = cOperando + (sExpresion[iIndice]-48);
								else
									if(cOperador=='-')
										iResult = cOperando - (sExpresion[iIndice]-48);
										else
											if(cOperador=='*')
												iResult = cOperando * (sExpresion[iIndice]-48);
												else
													if(cOperador == '/')
														iResult = cOperando / (sExpresion[iIndice]-48);
														else
															iResult = pow(cOperando,sExpresion[iIndice]-48);
								printf("Se realizo la operacion: %d %c %d = %d\n", cOperando, cOperador, sExpresion[iIndice]-48, iResult);
								SbPilaPush(&xPilaOperandos,iResult);
								iResult=0;
							while(!FnIntPilaVacia(&xPilaOperadores))
							{
								if(FnIntPilaCima(&xPilaOperadores) != '(')
								{
									cOperador = FnIntPilaPop(&xPilaOperadores);
									cOperando = FnIntPilaPop(&xPilaOperandos);
									cOperando2 = FnIntPilaPop(&xPilaOperandos);
									
									if(cOperador== '+')
										iResult = cOperando2 + cOperando;
									else
										if(cOperador == '-')
											iResult = cOperando2 - cOperando;
										else
											if(cOperador == '*')
												iResult = cOperando2 * cOperando;
											else
												if(cOperador == '/')
													iResult = cOperando2 / cOperando;
												else
													iResult = pow(cOperando2,cOperando);
									printf("Se realizo la operacion: %d %c %d = %d\n", cOperando, cOperador, cOperando2, iResult);
									
									SbPilaPush(&xPilaOperandos,iResult);
									iResult = 0;
								}
								else
								{
									printf("Error. Se encontro un %c sin cierre\n", FnIntPilaPop(&xPilaOperadores));
									iResult = -1;
								}
								
							}
						}
						else
							if(FnIntDigitosEs(sExpresion[iIndice+1]))
							{
								printf("Error. Falta un operador antes de %c\n", sExpresion[iIndice+1]);
								iResult=-1;
							}
						else
							if(FnIntOperadorEs(sExpresion[iIndice+1]))
							{
								if(FnIntMayorPrioridad(FnIntPilaCima(&xPilaOperadores), sExpresion[iIndice+1]))
								{
									cOperador = FnIntPilaPop(&xPilaOperadores);
									cOperando = FnIntPilaPop(&xPilaOperandos);
									
									if(cOperador == '+')
										iResult = cOperando + (sExpresion[iIndice]-48);
										else 
											if(cOperador == '-')
												iResult = cOperando - (sExpresion[iIndice]-48);
											else
												if(cOperador == '*')
													iResult = cOperando * (sExpresion[iIndice]-48);
												else
													if(cOperador == '/')
														iResult = cOperando + (sExpresion[iIndice]-48);
													else
														iResult = pow(cOperando,sExpresion[iIndice]-48);
										printf("Se realizo la operacion: %d %c %d = %d\n", cOperando, cOperador, sExpresion[iIndice]-48, iResult);
										
										SbPilaPush(&xPilaOperandos,iResult);
										iResult=0;
									}
									else
									{
										SbPilaPush(&xPilaOperandos, sExpresion[iIndice]-48);
										SbPilaPush(&xPilaOperadores, sExpresion[++iIndice]);
									}
									if(sExpresion[iIndice+1] == ')')
									{
										SbPilaPush(&xPilaOperandos,sExpresion[iIndice]-48);
									}
									else
										if(sExpresion[iIndice+1] == '(')
										{
											printf("Error. Se necesita un operador antes de un (\n");
											iResult = -1;
										}
								}
							else
							{
								printf("Error. Caracter no reconocido: %c\n", sExpresion[iIndice+1]);
								iResult=-1;
							}
						break;
				default: printf("Error. Caracter no reconocido: %c\n", sExpresion[iIndice]);
				iResult=-1;
			}
		}
			if(iResult==-1)
			break;
		}
	}
	if(iResult!=-1)
		if(FnIntPilaVacia(&xPilaOperadores))
		{
			iResult = FnIntPilaPop(&xPilaOperandos);
			printf("El resultado de la expresion %s es %d\n", sExpresion, iResult);
		}
		
	return (iResult);
														
}

