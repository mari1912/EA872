#include <iostream>
#include <memory>

//Model
class Model {
    private: 
        float x0, v0, dt, massa, k, b;
        float x_atual;
        float v_atual;
        float aceleracao;
    public:
        Model(float x0, float v0, float dt, float massa, float k, float b);
        float get_x_atual();
        float get_v_atual();
        float get_aceleracao();
        float get_k();
        float get_b();
        float get_massa();
        float get_dt();
        void set_x_atual(float x_novo);
        void set_v_atual(float v_novo);
        void set_aceleracao(float aceleracao_novo);
};

//Construtor
Model::Model(float x0, float v0, float dt, float massa, float k, float b) {
    this->x0 = x0;
    this->v0 = v0;
    this->dt = dt;
    this->massa = massa;
    this->k = k;
    this->b = b;
    x_atual = x0;
    v_atual = v0;
    aceleracao = 0;
}

//Permite acesso aos dados
float Model::get_x_atual(){
    return x_atual;
}

float Model::get_v_atual(){
    return v_atual;
}

float Model::get_aceleracao(){
    return aceleracao;
}

float Model::get_k(){
    return k;
}

float Model::get_b(){
    return b;
}

float Model::get_massa() {
    return massa;
}

float Model::get_dt(){
    return dt;
}

//Permite alterar os dados
void Model::set_x_atual(float x_novo){
    x_atual = x_novo;
}

void Model::set_v_atual(float v_novo){
    v_atual = v_novo;
}

void Model::set_aceleracao(float aceleracao_novo){
    aceleracao = aceleracao_novo;
}

//Controller
class Controller {
    private:
        std::shared_ptr<Model>model;
        float forca;
    public:
        Controller(std::shared_ptr<Model>model);
        void calcula_posicao();
};

//Construtor
Controller::Controller(std::shared_ptr<Model>model) {
    this->model = model;
}

//Calcula a proxima posicao
void Controller::calcula_posicao() {

    forca = -(model->get_x_atual())*(model->get_k()) - (model->get_v_atual())*(model->get_b());
    model->set_aceleracao(forca/(model->get_massa()));
    model->set_v_atual(model->get_v_atual()+model->get_aceleracao()*model->get_dt());
    model->set_x_atual(model->get_x_atual()+model->get_v_atual()*model->get_dt());   
}

//Main
int main() {

    std::shared_ptr<Model>modelo(new Model(1, 0, 0.1, 1, 1, 0));
    std::shared_ptr<Controller>controle_sistema(new Controller(modelo));
    
    for(int i=0; i<100; i++) {
        std::cout<<i<<":"<<modelo->get_x_atual()<<std::endl;
        controle_sistema->calcula_posicao();
    }

    return 0;
}