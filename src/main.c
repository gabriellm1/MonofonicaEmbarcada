/**
 * 5 semestre - Eng. da Computa��o - Insper
 /**
  ** Entrega realizada em parceria com:
  **  - Gabriel Monteiro - gabriellm1@al.insper.edu.br
  **  - Guilherme Leite -
  **
  **  - url vídeo
  **/

/************************************************************************/
/* includes                                                             */
/************************************************************************/

#include "asf.h"
#include "musics.h"

/************************************************************************/
/* defines                                                              */
/************************************************************************/
// defines do Buzzer
#define BUZZ_PIO           PIOA
#define BUZZ_PIO_ID        ID_PIOA
#define BUZZ_PIO_IDX       19u
#define BUZZ_PIO_IDX_MASK  (1u << BUZZ_PIO_IDX)
// Configurando Led
#define LED_PIO           PIOC                  // periferico que controla o LED
#define LED_PIO_ID        12                    // ID do perif�rico PIOC (controla LED)
#define LED_PIO_IDX       8u                    // ID do LED no PIO
#define LED_PIO_IDX_MASK  (1u << LED_PIO_IDX)   // Mascara para CONTROLARMOS o LED


void init(void);

/************************************************************************/
/* funcoes                                                              */
/************************************************************************/


// Fun��o de inicializa��o do uC
void init(void)
{
	  // Initialize the board clock
	  sysclk_init();

	  // Desativa WatchDog Timer
	  WDT->WDT_MR = WDT_MR_WDDIS;

	  // Ativa o PIO na qual o BUZZ foi conectado
	  // para que possamos controlar o BUZZ.
	  pmc_enable_periph_clk(BUZZ_PIO_ID);
	  //Inicializa PA19 como sa�da
	  pio_set_output(BUZZ_PIO, BUZZ_PIO_IDX_MASK, 1, 0, 0);

	    // Ativa o PIO na qual o LED foi conectado
	    // para que possamos controlar o LED.
	    pmc_enable_periph_clk(LED_PIO_ID);
	    //Inicializa PC8 como sa�da
	    pio_set_output(LED_PIO, LED_PIO_IDX_MASK, 1, 0, 0);
}

/************************************************************************/
/* Main                                                                 */
/************************************************************************/

// Funcao principal chamada na inicalizacao do uC.
int main(void)
{
  init();

  while(1){

		  for (int i=0;i<sizeof(piratas)/sizeof(piratas[0]);i++)
		  {
			  int aciona = piratas[i]*(((float) dur_piratas[i])/1000.0);
			  for(int w=aciona;w>=0;w--)
			  {
				  pio_set(BUZZ_PIO, BUZZ_PIO_IDX_MASK);
				  delay_us(500000/piratas[i]);
				  pio_clear(BUZZ_PIO, BUZZ_PIO_IDX_MASK);
				  delay_us(500000/piratas[i]);
				  pio_set(LED_PIO,LED_PIO_IDX_MASK);
			  }
			  pio_clear(LED_PIO,LED_PIO_IDX_MASK);
		 }

		//pio_clear(BUZZ_PIO, BUZZ_PIO_IDX_MASK);
		delay_s(2);
  }
  return 0;
}
