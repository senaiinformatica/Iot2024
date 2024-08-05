#pragma onde

const int fusoHorario = -10800;
const unsigned long atualizaNTP = 60000; // em milissegundos

//Retorna a hora atual no formato hh:mm:ss
void hora_certa();

//Retorna tempo no formato POSIX(unsigned long)
unsigned long timeStamp();

//Configura o servidor NTP
void setup_time();

//Atualiza o servidor NTP
void atualiza_time();