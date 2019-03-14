/**
 * 5 semestre - Eng. da Computa��o - Insper

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
// defines do Botao de start
#define BUTTSTART_PIO           PIOC
#define BUTTSTART_PIO_ID        ID_PIOC
#define BUTTSTART_PIO_IDX       17u
#define BUTTSTART_PIO_IDX_MASK  (1u << BUTTSTART_PIO_IDX)
// defines do Botao de next
#define BUTTNEXT_PIO           PIOC
#define BUTTNEXT_PIO_ID        ID_PIOC
#define BUTTNEXT_PIO_IDX       30u
#define BUTTNEXT_PIO_IDX_MASK  (1u << BUTTNEXT_PIO_IDX)


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
		
	 pmc_enable_periph_clk(BUTTSTART_PIO_ID);
	 // configura pino ligado ao bot�o como entrada com um pull-up.
	 pio_set_input(BUTTSTART_PIO,BUTTSTART_PIO_IDX_MASK,PIO_DEFAULT);
	 // ativa pullup
	 pio_pull_up(BUTTSTART_PIO, BUTTSTART_PIO_IDX_MASK, 1);
	 //next
	 pmc_enable_periph_clk(BUTTNEXT_PIO_ID);
	 // configura pino ligado ao bot�o como entrada com um pull-up.
	 pio_set_input(BUTTNEXT_PIO,BUTTNEXT_PIO_IDX_MASK,PIO_DEFAULT);
	 // ativa pullup
	 pio_pull_up(BUTTNEXT_PIO, BUTTNEXT_PIO_IDX_MASK, 1);
}

void play(int i,int duration[],int notes[],int n){
	int aciona = notes[i]*(((float) duration[i])/1000.0);
	for(int w=aciona;w>=0;w--)
	{ 
			pio_set(PIOA, BUZZ_PIO_IDX_MASK);
			delay_us(500000/notes[i]);
			pio_clear(PIOA, BUZZ_PIO_IDX_MASK);
			pio_set(LED_PIO,LED_PIO_IDX_MASK);
			delay_us(500000/notes[i]);
}
	delay_us(80000);
	pio_clear(LED_PIO,LED_PIO_IDX_MASK);
}

/************************************************************************/
/* Main                                                                 */
/************************************************************************/

// Funcao principal chamada na inicalizacao do uC.
int main(void){
  init();
  int n=0;

  while(1){
	if(pio_get(BUTTSTART_PIO,PIO_INPUT ,BUTTSTART_PIO_IDX_MASK)==0){
		int *playing_notes = piratas;
		int *playing_dura = dur_piratas;

		  for (int i=0;i<sizeof(piratas)/sizeof(piratas[0]);i++){
			if(pio_get(BUTTNEXT_PIO,PIO_INPUT ,BUTTNEXT_PIO_IDX_MASK)==0){
				i=0;
				delay_s(1);

				if(n%2==0){
					playing_notes = mario;
					playing_dura = dur_mario;
				}
				
				else{
					playing_notes = piratas;
					playing_dura = dur_piratas;
				}
				
				n++;
			}
			if(pio_get(BUTTSTART_PIO,PIO_INPUT ,BUTTSTART_PIO_IDX_MASK)==0){
				int pause =1;
				delay_s(1);
				while(pause){
					if(pio_get(BUTTSTART_PIO,PIO_INPUT ,BUTTSTART_PIO_IDX_MASK)==0){
						pause=0;
						delay_s(0.5);

					}
				}
			}

			play(i,playing_dura,playing_notes,n);
		}
	}
 			
		else{
			pio_clear(BUZZ_PIO, BUZZ_PIO_IDX_MASK);
			pio_set(LED_PIO, LED_PIO_IDX_MASK);

		}
	}
}

		
