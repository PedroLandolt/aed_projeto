#include "headers/GestaoHorario.h"

int main() {
    
    cout << " A iniciar o programa..." << endl;
    

    GestaoHorario gh;
    Sort sorts;


    cout << " A ler o ficheiro students_classes.csv..." << endl;

    //Leitura dos ficheiros
    vector<Estudante> v_estudantes;
    gh.lerFichEst(v_estudantes); //retorna um set de estudantes



// dar print ao vector de estudantes choura de minas!
/*
    int estudante_n = 1;
    for(auto i : v_estudantes){
        cout << choura << " - " << i.getEstudantePair().first << " " << i.getEstudantePair().second << endl;
        for(auto j : i.getEstudanteInscrito()){
            cout << j.getUCTurma().first << " " << j.getUCTurma().second << endl;
        }
        cout << "UC's: " << i.getEstudanteInscrito().size() << endl;
        cout << endl;
        cout << "||||||||||||||||||||||||||||||||" << endl;
        cout << endl;
        estudante_n++;
    }
*/

    struct EstudanteCompare {
        bool operator()(Estudante* lhs, Estudante* rhs) const {
            return lhs->getEstudantePair().first < rhs->getEstudantePair().first;
        }
    };

    set<Estudante*, EstudanteCompare> s_estudantes;

    for(const auto& i : v_estudantes){
        auto *p = new Estudante(i);
        s_estudantes.insert(p);
    }

    cout << " Ficheiro lido com sucesso!" << endl;
    cout << " A ler o ficheiro classes.csv..." << endl;

    vector<THorario> v_horarios;
    gh.lerFichHorario(v_horarios); //retorna um vector de horarios

    set<THorario> s_horarios(v_horarios.begin(), v_horarios.end());

    vector<Slot> v_slots;
    gh.lerFichSlot(v_slots); //retorna um vector de slots

    struct slotCompareTurma {
        bool operator()(Slot* lhs, Slot* rhs) const {
            return lhs->getUcTurma().second < rhs->getUcTurma().second;
        }
    };

    struct slotCompareUc {
        bool operator()(Slot* lhs, Slot* rhs) const {
            return lhs->getUcTurma().first < rhs->getUcTurma().first;
        }
    };

    set<Slot*, slotCompareTurma> s_slots_turma;
    set<Slot*, slotCompareUc> s_slots_uc;

    for(const auto& i : v_slots){
        auto *p = new Slot(i);
        s_slots_turma.insert(p);
        s_slots_uc.insert(p);
    }
/*
    for(auto i : v_slots){
        cout << i.getUcTurma().first << " " << i.getUcTurma().second << " " << i.getDiaSemana() << endl;
    }
*/
/* print do vector de horarios

    int horario_n = 1;
    for(auto i : v_horarios){
        cout << horario_choura << " - " << i.getUcTurma().first << " " << i.getUcTurma().second << endl;
        for(auto j : i.getHoraUCTurma()){
            cout << j.getDiaSemana() << " | Inicio: " << j.getHora().first << " | Duracao: " << j.getHora().second << " | Tipo: " << j.getTipo()  << endl;
        }
        cout << " Numero de aulas por semana: " << i.getHoraUCTurma().size() << endl;
        cout << endl;
        cout << "||||||||||||||||||||||||||||||||" << endl;
        cout << endl;
        horario_n++;
    }
*/

    cout << " Ficheiro lido com sucesso!" << endl;
    cout << " A ler o ficheiro classes_per_uc.csv..." << endl;

    vector<UCTurma> v_ucturma;
    gh.lerFichUCTurma(v_ucturma); //retorna um vector de ucturma

    set<UCTurma> s_ucturma(v_ucturma.begin(), v_ucturma.end());

// print do vector de ucturma
/*
    int ucturma_n = 1;
    for(auto i : v_ucturma){
        cout << ucturma_choura << " - " << i.getUCTurma().first << " " << i.getUCTurma().second << endl;
        ucturma_n++;
        cout << endl;
        cout << "||||||||||||||||||||||||||||||||" << endl;
        cout << endl;
    }
*/

    cout << " Ficheiro lido com sucesso!" << endl;

    cout << " A iniciar o processamento..." << endl;

    int choice;

    string uc_caso2 , uc_caso4, uc_caso8, uc_caso10;
    string turma_caso3, turma_caso4, turma_caso7, turma_caso9, turma_caso10;
    string nome_estudante_caso6, nome_estudante_caso10;
    char ano_caso5;
    int id_estudante_caso6, id_estudante_caso10;
    pair<string,string> uc_turma_caso4, uc_turma_caso10;
    pair<int,string> estudante_caso6, estudante_caso10, estudante_caso1;
    vector<pair<int,string>> v_estudante_caso2, v_estudante_caso3, v_estudante_caso4, v_estudante_caso5;


    //Pedidos de mudança de turma
    //gh.getPedidos();
    //gh.processsar();
    //gh.listagem();


    //menu
    cout << " A inciar o menu..." << endl;
    cout << endl;


    do{
        gh.clear();
        cout << " Escolha uma opcao: " << endl;
        cout << endl;
        cout << " 0 - Sair" << endl;
        cout << " 1 - Listar estudantes" << endl;
        cout << " 2 - Listar estudantes inscritos numa UC" << endl;
        cout << " 3 - Listar estudantes inscritos numa turma" << endl;
        cout << " 4 - Listar estudantes inscritos numa UC e turma" << endl;
        cout << " 5 - Listar estudantes incritos num dado ano" << endl;
        cout << " 6 - Mostrar horario de um estudante" << endl;
        cout << " 7 - Mostrar horario de uma turma" << endl;
        cout << " 8 - Mostrar horario de uma UC" << endl;
        cout << " 9 - Fazer pedidos de mudanca de turma" << endl;
        cout << " 10 - Listar pedidos de mudanca de turma" << endl;
        cout << " 11 - Processar pedidos de mudanca de turma" << endl;
        cout << endl;

        cin >> choice;
        cout << endl;



        switch(choice){
            case 0:
                choice = 0;
                break;


            //Listar estudantes
            case 1:
                
                int choice1;
                choice = 1;

                do{
                    gh.clear();
                    cout << " Escolha uma opcao: " << endl;
                    cout << endl;
                    cout << " 0 - Back" << endl;
                    cout << " 1 - Ordenar estudantes por UP crescente" << endl;
                    cout << " 2 - Ordenar estudantes por UP decrescente" << endl;
                    cout << " 3 - Ordenar estudantes por nome A-Z" << endl;
                    cout << " 4 - Ordenar estudantes por nome Z-A" << endl;
                    cout << endl;

                    cin >> choice1;
                    cout << endl;

                    switch(choice1){
                        case 0:
                            choice1 = 0;
                            /**
                             * Deve voltar ao menu principal
                             */
                            break;

                        case 1:
                            choice1 = 1;
                            /**
                             * @return lista ordenada estudantes por UP de forma crescente
                             */

                            sorts.sortUPCrescente(v_estudantes);

                            for(auto p : v_estudantes){
                                cout << " UP: " << p.getEstudantePair().first << " | Nome: " << p.getEstudantePair().second << endl;
                            }

                            cout << endl;
                            break;

                        case 2:
                            choice1 = 2;
                            /**
                             * @return lista ordenada estudantes por UP de forma decrescente
                             */
                            
                            sorts.sortUPDecrescente(v_estudantes);
                            
                            for(auto p : v_estudantes){
                                cout << " UP: " << p.getEstudantePair().first << " | Nome: " << p.getEstudantePair().second << endl;
                            }

                            cout << endl;

                            break;

                        case 3:
                            choice1 = 3;
                            /**
                             * @return lista ordenada estudantes por nome de forma A-Z
                             */
                            
                            sorts.sortNomeCrescente(v_estudantes);

                            for(auto p : v_estudantes){
                                cout << " UP: " << p.getEstudantePair().first << " | Nome: " << p.getEstudantePair().second << endl;
                            }

                            cout << endl;

                            break;
                        
                        case 4:
                            choice1 = 4;
                            /**
                             * @return lista ordenada estudantes por nome de forma Z-A
                             */

                            sorts.sortNomeDecrescente(v_estudantes);

                            for(auto p : v_estudantes){
                                cout << " UP: " << p.getEstudantePair().first << " | Nome: " << p.getEstudantePair().second << endl;
                            }
                            
                            break;

                        default:
                            cout << " Opcao invalida" << endl;
                            break;
                    }

                } while (choice1 != 0);
                
                break;


            //Listar estudantes inscritos numa UC
            
            case 2:

                choice = 2;
                int choice2;
                
                cout << " UC: ";
                cin >> uc_caso2;

                do{

                    cout << endl;
                    cout << " UC escolhida: " << uc_caso2 << endl;
                    cout << endl;

                    //iff com while para verificar se a UC existe


                    //limpar lixo de v_estudante_caso2
                    v_estudante_caso2.clear();
                    //listar estudantes inscritos na UC
                    for(auto p : v_estudantes){
                        auto j = p.getEstudanteInscrito();
                        for(auto i : j){
                            if(i.getUCTurma().first == uc_caso2){
                                v_estudante_caso2.push_back(p.getEstudantePair());
                            }
                        }
                    }

                    cin >> choice2;
                    cout << endl;

                    if(v_estudante_caso2.empty()){
                        cout << " Nao existem estudantes inscritos nesta UC" << endl;
                        choice2 = 5;
                        break;
                    }
                    cout << " Escolha uma opcao: " << endl;
                    cout << endl;
                    cout << " 0 - Back" << endl;
                    cout << " 1 - Ordenar estudantes por UP crescente" << endl;
                    cout << " 2 - Ordenar estudantes por UP decrescente" << endl;
                    cout << " 3 - Ordenar estudantes por nome A-Z" << endl;
                    cout << " 4 - Ordenar estudantes por nome Z-A" << endl;
                    cout << " 5 - Escolher outra UC" << endl;
                    cout << endl;

                    switch(choice2){
                        case 0:
                            choice2 = 0;
                            /**
                             * Deve voltar ao menu principal
                             */
                            break;

                        case 1:
                            choice2 = 1;
                            /**
                             * @return lista ordenada estudantes por UP de forma crescente
                             */

                            sorts.sortPairCrescente(v_estudante_caso2);

                            for(auto pup : v_estudante_caso2){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            break;

                        case 2:
                            choice2 = 2;
                            /**
                             * @return lista ordenada estudantes por UP de forma decrescente
                             */

                            sorts.sortPairDecrescente(v_estudante_caso2);

                            for(auto pup : v_estudante_caso2){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            break;

                        case 3:
                            choice2 = 3;
                            /**
                             * @return lista ordenada estudantes por nome de forma A-Z
                             */

                            sorts.sortPairNomeCrescente(v_estudante_caso2);

                            for(auto pup : v_estudante_caso2){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            break;
                        
                        case 4:
                            choice2 = 4;
                            /**
                             * @return lista ordenada estudantes por nome de forma Z-A
                             */

                            sorts.sortPairNomeDecrescente(v_estudante_caso2);

                            for(auto pup : v_estudante_caso2){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            break;

                        case 5:
                            choice2 = 5;

                            /**
                             * @brief Escolher outra UC
                             */

                            cout << " UC: ";
                            cin >> uc_caso2;
                            cout << endl;

                            break;

                        default:
                            cout << " Opcao invalida" << endl;
                            break;
                    }

                } while (choice2 != 0);
                
                break;
            

            //Listar estudantes inscritos numa turma
            case 3:
                choice = 3;
                int choice3;

                cout << " Turma: ";
                cin >> turma_caso3;



                do{
                        
                    cout << endl;
                    cout << " Turma escolhida: " << turma_caso3 << endl;
                    cout << endl;

                    //iff com while para verificar se a turma existe

                    //limpa o lixo de v_estudante_caso3
                    v_estudante_caso3.clear();
                    //listar estudantes inscritos na turma
                    for(auto p : v_estudantes){
                        auto j = p.getEstudanteInscrito();
                        for(auto i : j){
                            if(i.getUCTurma().second == turma_caso3){
                                v_estudante_caso3.push_back(p.getEstudantePair());
                            }
                        }
                    }

                    //remover dups
                    for(auto x = v_estudante_caso3.begin(); x != v_estudante_caso3.end(); x++){
                        for(auto y = x + 1; y != v_estudante_caso3.end(); y++){
                            if(x->first == y->first){
                                v_estudante_caso3.erase(y);
                                y--;
                            }
                        }
                    }

                    cout << " Escolha uma opcao: " << endl;
                    cout << endl;
                    cout << " 0 - Back" << endl;
                    cout << " 1 - Ordenar estudantes por UP crescente" << endl;
                    cout << " 2 - Ordenar estudantes por UP decrescente" << endl;
                    cout << " 3 - Ordenar estudantes por nome A-Z" << endl;
                    cout << " 4 - Ordenar estudantes por nome Z-A" << endl;
                    cout << " 5 - Escolher outra turma" << endl;
                    cout << endl;

                    cin >> choice3;

                    switch(choice3){
                        case 0:
                            choice3 = 0;
                            /**
                            * Deve voltar ao menu principal
                            */
                            break;

                        case 1:
                            choice3 = 1;
                            /**
                            * @return lista ordenada estudantes por UP de forma crescente
                            */

                            sorts.sortPairCrescente(v_estudante_caso3);

                            for(auto pup : v_estudante_caso3){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            break;

                        case 2:
                            choice3 = 2;
                            /**
                            * @return lista ordenada estudantes por UP de forma decrescente
                            */

                            sorts.sortPairDecrescente(v_estudante_caso3);

                            for(auto pup : v_estudante_caso3){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            break;

                        case 3:
                            choice3 = 3;
                            /**
                            * @return lista ordenada estudantes por nome de forma A-Z
                            */

                            sorts.sortPairNomeCrescente(v_estudante_caso3);

                            for(auto pup : v_estudante_caso3){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            break;
                        
                        case 4:
                            choice3 = 4;
                            /**
                            * @return lista ordenada estudantes por nome de forma Z-A
                            */

                            sorts.sortPairNomeDecrescente(v_estudante_caso3);

                            for(auto pup : v_estudante_caso3){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            break;

                        case 5:
                            choice3 = 5;

                            /**
                            * @brief Escolher outra turma
                            */

                            cout << " Turma: ";
                            cin >> turma_caso3;
                            cout << endl;

                            break;

                        default:
                            cout << " Opcao invalida" << endl;
                            break;
                    }
    
                } while (choice3 != 0);
                break;

            //Listar estudantes inscritos numa UC e turma
            case 4:
                choice = 4;
                int choice4;

                cout << " UC: ";
                cin >> uc_caso4;
                cout << " Turma: ";
                cin >> turma_caso4;

                uc_turma_caso4 = make_pair(uc_caso4, turma_caso4);

                do{
                        
                    cout << endl;
                    cout << " UC escolhida: " << uc_caso4 << endl;
                    cout << " Turma escolhida: " << turma_caso4 << endl;
                    cout << endl;

                    //iff com while para verificar se a uc / turma existe

                    //limpar o lixo dentro de v_estudante_caso4
                    v_estudante_caso4.clear();
                    //listar estudantes inscritos na uc / turma
                    for(auto p : v_estudantes){
                        auto j = p.getEstudanteInscrito();
                        for(auto i : j){
                            if(i.getUCTurma() == uc_turma_caso4){
                                v_estudante_caso4.push_back(p.getEstudantePair());
                            }
                        }
                    }

                    cout << " Escolha uma opcao: " << endl;
                    cout << endl;
                    cout << " 0 - Back" << endl;
                    cout << " 1 - Ordenar estudantes por UP crescente" << endl;
                    cout << " 2 - Ordenar estudantes por UP decrescente" << endl;
                    cout << " 3 - Ordenar estudantes por nome A-Z" << endl;
                    cout << " 4 - Ordenar estudantes por nome Z-A" << endl;
                    cout << " 5 - Escolher outra UC" << endl;
                    cout << " 6 - Escolher outra turma" << endl;
                    cout << " 7 - Escolher outra UC e turma" << endl;
                    cout << endl;

                    cin >> choice4;

                    switch(choice4){
                        case 0:
                            choice4 = 0;
                            /**
                            * Deve voltar ao menu principal
                            */
                            break;

                        case 1:
                            choice4 = 1;
                            /**
                            * @return lista ordenada estudantes por UP de forma crescente
                            */

                            sorts.sortPairCrescente(v_estudante_caso4);

                            for(auto pup : v_estudante_caso4){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            break;

                        case 2:
                            choice4 = 2;
                            /**
                            * @return lista ordenada estudantes por UP de forma decrescente
                            */

                            sorts.sortPairDecrescente(v_estudante_caso4);

                            for(auto pup : v_estudante_caso4){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            break;

                        case 3:
                            choice4 = 3;
                            /**
                            * @return lista ordenada estudantes por nome de forma A-Z
                            */

                            sorts.sortPairNomeCrescente(v_estudante_caso4);

                            for(auto pup : v_estudante_caso4){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            break;
                        
                        case 4:
                            choice4 = 4;
                            /**
                            * @return lista ordenada estudantes por nome de forma Z-A
                            */

                            sorts.sortPairNomeDecrescente(v_estudante_caso4);

                            for(auto pup : v_estudante_caso4){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            break;

                        case 5:
                            choice4 = 5;

                            /**
                            * @brief Escolher outra UC
                            */

                            cout << " UC: ";
                            cin >> uc_caso4;

                            uc_turma_caso4 = make_pair(uc_caso4, turma_caso4);

                            break;

                        case 6:
                            choice4 = 6;

                            /**
                            * @brief Escolher outra turma
                            */

                            cout << " Turma: ";
                            cin >> turma_caso4;

                            uc_turma_caso4 = make_pair(uc_caso4, turma_caso4);

                            break;
                        
                        case 7:
                            choice4 = 7;

                            /**
                            * @brief Escolher outra UC e turma
                            */

                            cout << " UC: ";
                            cout << " Turma: ";
                            cin >> uc_caso4 >> turma_caso4;

                            uc_turma_caso4 = make_pair(uc_caso4, turma_caso4);

                            break;

                        default:
                            cout << " Opcao invalida" << endl;
                            break;

                    }
                } while(choice4 != 0);

                break;

            //Listar estudantes incritos num determinado ano
            case 5:
                choice = 5;
                int choice5;



                cout << " Ano: ";
                cin >> ano_caso5;

                do{

                    cout << endl;
                    cout << " Ano escolhido: " << ano_caso5 << endl;
                    cout << endl;


                    //limpar o lixo dentro de v_estudante_caso5
                    v_estudante_caso5.clear();
                    //listar estudantes inscritos no ano
                    for(auto p : v_estudantes){
                        auto j = p.getEstudanteInscrito();
                        for(auto i : j){
                            if(i.getUCTurma().second[0] == ano_caso5){
                                v_estudante_caso5.push_back(p.getEstudantePair());
                            }
                        }
                    }

                    //limpar dups
                    for(auto x = v_estudante_caso5.begin(); x != v_estudante_caso5.end(); x++){
                        for(auto y = x + 1; y != v_estudante_caso5.end(); y++){
                            if(x->first == y->first){
                                v_estudante_caso5.erase(y);
                                y--;
                            }
                        }
                    }

                    cout << " Escolha uma opcao: " << endl;
                    cout << endl;
                    cout << " 0 - Back" << endl;
                    cout << " 1 - Ordenar estudantes por UP crescente" << endl;
                    cout << " 2 - Ordenar estudantes por UP decrescente" << endl;
                    cout << " 3 - Ordenar estudantes por nome A-Z" << endl;
                    cout << " 4 - Ordenar estudantes por nome Z-A" << endl;
                    cout << " 5 - Escolher outro ano" << endl;
                    cout << endl;

                    cin >> choice5;

                    switch(choice5){
                        case 0:
                            choice5 = 0;
                            /**
                            * Deve voltar ao menu principal
                            */
                            break;

                        case 1:
                            choice5 = 1;
                            /**
                            * @return lista ordenada estudantes por UP de forma crescente
                            */

                            sorts.sortPairCrescente(v_estudante_caso5);

                            for(auto pup : v_estudante_caso5){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            break;

                        case 2:
                            choice5 = 2;
                            /**
                            * @return lista ordenada estudantes por UP de forma decrescente
                            */

                            sorts.sortPairDecrescente(v_estudante_caso5);

                            for(auto pup : v_estudante_caso5){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            break;

                        case 3:
                            choice5 = 3;
                            /**
                            * @return lista ordenada estudantes por nome de forma A-Z
                            */

                            sorts.sortPairNomeCrescente(v_estudante_caso5);

                            for(auto pup : v_estudante_caso5){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            break;
                        
                        case 4:
                            choice5 = 4;
                            /**
                            * @return lista ordenada estudantes por nome de forma Z-A
                            */

                            sorts.sortPairNomeDecrescente(v_estudante_caso5);

                            for(auto pup : v_estudante_caso5){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            break;
                        
                        case 5:
                            choice5 = 5;

                            /**
                            * @brief Escolher outro ano
                            */

                            cout << " Ano: ";
                            cin >> ano_caso5;
                            cout << endl;

                            break;

                        default:
                            cout << " Opcao invalida" << endl;
                            break;
                    }
                } while(choice5 != 0);
                break;

            //Mostrar horario de um estudante
            case 6:
                choice = 6;
                int choice6;

                cout << " UP: ";
                cin >> id_estudante_caso6;


                do{

                    //Lista as disciplinas do estudante
                    list<UCTurma> l_ucturma_caso6;
                    for(auto p : s_estudantes){
                        if(p->getEstudantePair().first == id_estudante_caso6){
                            l_ucturma_caso6 = p->getEstudanteInscrito();
                            cout << " Estudante: " << p->getEstudantePair().second << endl;
                        }
                    }


                    vector<Slot> slot_ucturma_caso6;
                    Slot slot_caso6;

                    for(auto p : l_ucturma_caso6){
                        for(auto i : v_slots){
                            if(p.getUCTurma() == i.getUcTurma()){
                                slot_ucturma_caso6.push_back(i);
                            }
                        }
                    }

                    slot_caso6.printSlot(slot_ucturma_caso6);

                    //cout horario estudante
                    cout << " Escolha uma opcao: " << endl;
                    cout << endl;
                    cout << " 0 - Back" << endl;
                    cout << " 1 - Escolher outro estudante" << endl;
                    cout << endl;

                    cin >> choice6;

                    switch(choice6){
                        case 0:
                            choice6 = 0;
                            /**
                            * Deve voltar ao menu principal
                            */
                            break;

                        case 1:
                            choice6 = 1;

                            /**
                            * @brief Escolher outro estudante
                            */
                            cout << endl;
                            cout << " UP: ";
                            cin >> id_estudante_caso6;


                            break;

                        default:
                            cout << " Opcao invalida" << endl;
                            break;
                    }
                } while(choice6 != 0);

                break;

            //Mostrar horario de uma turma
            case 7:
                choice = 7;
                int choice7;

                cout << " Turma: ";
                cin >> turma_caso7;

                do{

                    vector<Slot> slot_ucturma_caso7;
                    Slot slot_caso7;

                    for(auto p : v_slots){
                        if(p.getUcTurma().second == turma_caso7){
                            slot_ucturma_caso7.push_back(p);
                        }
                    }

                    slot_caso7.printSlot(slot_ucturma_caso7);

                    //cout horario turma
                    cout << " Escolha uma opcao: " << endl;
                    cout << endl;
                    cout << " 0 - Back" << endl;
                    cout << " 1 - Escolher outra turma" << endl;
                    cout << endl;

                    cin >> choice7;

                    switch(choice7){
                        case 0:
                            choice7 = 0;
                            /**
                            * Deve voltar ao menu principal
                            */
                            break;

                        case 1:
                            choice7 = 1;

                            /**
                            * @brief Escolher outra turma
                            */

                            cout << " Turma: ";
                            cin >> turma_caso7;

                            break;

                        default:
                            cout << " Opcao invalida" << endl;
                            break;
                    }
                } while(choice7 != 0);
                
                break;

            //Mostrar horario de uma UC
            case 8:
                choice = 8;
                int choice8;

                cout << " UC: ";
                cin >> uc_caso8;

                do{

                    vector<Slot> slot_ucturma_caso8;
                    Slot slot_caso8;

                    for(auto p : v_slots){
                        if(p.getUcTurma().first == uc_caso8){
                            slot_ucturma_caso8.push_back(p);
                        }
                    }

                    slot_caso8.printSlot(slot_ucturma_caso8);

                    //cout horario UC
                    cout << " Escolha uma opcao: " << endl;
                    cout << endl;
                    cout << " 0 - Back" << endl;
                    cout << " 1 - Escolher outra UC" << endl;
                    cout << endl;

                    cin >> choice8;

                    switch(choice8){
                        case 0:
                            choice8 = 0;
                            /**
                            * Deve voltar ao menu principal
                            */
                            break;

                        case 1:
                            choice8 = 1;

                            /**
                            * @brief Escolher outra UC
                            */

                            cout << " UC: ";
                            cin >> uc_caso8;

                            break;

                        default:
                            cout << " Opcao invalida" << endl;
                            break;
                    }
                    
                } while (choice8 != 0);
                
                break;

            //Fazer pedido de mudanca de turma
            case 9:
                choice = 9;

                cout << " Escolha uma opcao: " << endl;
                cout << endl;
                cout << " 0 - Back" << endl;
                cout << " 1 - Fazer um pedido" << endl;
                cout << endl;

                int choice9;
                cin >> choice9;

                gh.clear();
                cout << " Introduza o seu UP: ";
                cin >> id_estudante_caso10;

                do{


                    //confirmar se o estudante existe

                    //confirmado

                    Estudante e_caso10;

                    //Complexidade O(n)
                    for(auto p : s_estudantes){
                        if(p->getEstudantePair().first == id_estudante_caso10){
                            e_caso10 = *p;
                        }
                    }

                    /////////////////////////////////////////////
                    gh.clear();
                    cout << " Introduza o nome da UC para qual quer mudar: ";
                    cin >> uc_caso10;

                    cout << " Introduza o nome da turma para qual quer mudar: ";
                    cin >> turma_caso10;

                    uc_turma_caso10 = make_pair(uc_caso10, turma_caso10);

                    for(auto p : e_caso10.getEstudanteInscrito()){
                        if(p.getUCTurma() == uc_turma_caso10){
                            cout << " Ja esta inscrito nessa turma" << endl;
                            break;
                        }
                        else if(p.getUCTurma().first == uc_caso10 && p.getUCTurma().second != turma_caso10 && p.getUCTurma().second[0] == turma_caso10[0]){
                            UCTurma uc_turma_caso10_tmp(uc_turma_caso10);
                            Pedido pedido_caso10(e_caso10, uc_turma_caso10);
                            gh.guardar(pedido_caso10);
                            cout << " Pedido de mudanca de turma enviado" << endl;
                            break;
                        }
                        else{
                            cout << "Pedido invalido" << endl;
                            break;
                        }
                    }
                } while (choice9 != 0);

                break;

            //Listar pedidos de mudanca de turma
            case 10:
                choice = 10;
                
                //cout pedidos de mudanca de turma

                break;

            //Processar pedidos de mudanca de turma "FIFO"
            case 11:
                choice = 11;
                int choice12;

                do{
                    
                    //cout primeiro pedido de mudanca de turma

                    cout << endl;
                    cout << " 0 - Back" << endl;
                    cout << " 1 - Processar Pedido" << endl;
                    cout << endl;

                    cin >> choice12;

                    switch(choice12){
                        case 0:
                            choice12 = 0;
                            /**
                            * Deve voltar ao menu principal
                            */
                            break;

                        case 1:
                            choice12 = 1;

                            /**
                             * Aceita pedido e remove da queue 
                             * Mudar uc e turma do estudante
                             *
                             * @brief Processar pedidos
                            */

                            break;

                        default:
                            cout << " Opcao invalida" << endl;
                            break;
                    }
                    
                } while (choice12 != 0);
                break;

            default:
                cout << " Opcao invalida" << endl;
                break;
        }
    }while(choice != 0);

    return 0;
}
