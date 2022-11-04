#ifndef AED_PROJETO_ESTUDANTE_H
#define AED_PROJETO_ESTUDANTE_H

#include "UCTurma.h"   /** O header 'UCTurma.h' contém definições de constantes usadas neste header */


class Estudante {
public:

    /** Default constructor */
    Estudante();


    /** Constructor
     * @param estudante Par de um valor integer (numero UP Estudante) e uma string (Nome do Estudante)
     * @param inscrito Lista de objetos UCTurma
    */
    Estudante(pair<int, string> estudante, list<UCTurma> inscrito);


    /** Default Getter
     * @return Um objeto do tipo Estudante
    */
    auto getEstudante();


    /** Getter
     * @return O pair Número do estudante(UP), Nome do Estudante
    */
    pair<int,string> getEstudantePair();


    /** Getter
     * @return A lista de objetos UCTurma em que o estudante está inscrito
    */
    list<UCTurma>& getEstudanteInscrito();


    /** Setter
     * @param estudante Par composto por um inteiro (Número do estudante(UP)) e uma string (Nome do Estudante)
     * @param inscrito Lista de objetos UCTurma em que o estudante está inscrito
    */
    void setEstudante(pair<int, string> estudante, list<UCTurma> inscrito);


    /** Setter
     * @param estudante Par composto por um inteiro (Número do estudante(UP)) e uma string (Nome do Estudante)
    */
    void setEstudantePair(pair<int, string> estudante);


    /** Setter
     * @param inscrito Lista de objetos UCTurma em que o estudante está inscrito
    */
    void setEstudanteInscrito(list<UCTurma> inscrito);


    /** Operator overload para comparar objetos do tipo Estudante */
    bool operator<(const Estudante &e) const;


private:

    pair<int,string> estudante;   /** Par composto por um inteiro (Número do estudante(UP)) e uma string (Nome do Estudante) */
    list<UCTurma> inscrito;       /** Lista de objetos UCTurma em que o estudante está inscrito */


};


#endif //AED_PROJETO_ESTUDANTE_H
