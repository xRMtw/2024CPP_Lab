#include <bits/stdc++.h>
using namespace std;
class Gate
{
    public :
        Gate *input[2] ;
        virtual bool output() = 0 ;
  		void setValue(Gate *, int) ;
        void setValue(bool, int) ;
} ;

class TRUE : public Gate
{
    public :
        virtual bool output() { return 1 ; }
        void setValue(Gate *, int) {}
        void setValue(bool, int) {}
} ;

class FALSE : public Gate
{
    public :
        virtual bool output() { return 0 ; }
        void setValue(Gate *, int) {}
        void setValue(bool, int) {}
} ;

TRUE t ;
FALSE f ;

void Gate::setValue(bool val, int pin)
{
    if(val) this -> input[pin] = &t ;
    else this -> input[pin] = &f ;
}

void Gate::setValue(Gate *gate, int pin) { this -> input[pin] = gate ; }

class NOT : public Gate
{
    public :
        virtual bool output() { return !(this -> input[0] -> output()) ; }
        void setValue(bool val, int pin = 0)
        {
        	if(val) this -> input[0] = &t ;
            else this -> input[0] = &f ;
        }
        void setValue(Gate* gate, int pin = 0) { this -> input[0] = gate ; }
} ;

class NAND : public Gate
{
    public :
        virtual bool output() { return !(this -> input[0] -> output()) || !(this -> input[1] -> output()) ; }
} ;

class NOR : public Gate
{
    public :
        virtual bool output() { return !(this -> input[0] -> output()) && !(this -> input[1] -> output()) ; }
} ;

class AND : public Gate
{
    public :
        AND() : Gate() {
            component[0]=new NOT;
            component[1]=new NAND;
        }
        virtual bool output() {
            component[1] -> input[0] = this -> input[0] ;
            component[1] -> input[1] = this -> input[1] ;
            component[0] -> input[0] = component[1] ;
            return component[0] -> output() ;
        }
    private :
        Gate *component[2] ;
} ;

class OR : public Gate
{
    public :
        OR() : Gate() {
            component[0]=new NOT;
            component[1]=new NOR;
        }
        virtual bool output() {
            component[1] -> input[0] = this -> input[0] ;
            component[1] -> input[1] = this -> input[1] ;
            component[0] -> input[0] = component[1] ;
            return component[0] -> output() ;
        }
    private :
        Gate *component[2] ;
} ;

class XOR : public Gate
{
    public :
        XOR() : Gate() {
            component[0]=new NOT;
            component[1]=new NOT;
            component[2]=new AND;
            component[3]=new AND;
            component[4]=new OR;
        }
        virtual bool output() {
            component[0]->input[0]=this->input[0];
            component[1]->input[0]=this->input[1];
            component[2]->input[0]=component[0];
            component[2]->input[1]=this->input[1];
            component[3]->input[0]=this->input[0];
            component[3]->input[1]=component[1];
            component[4]->input[0]=component[2];
            component[4]->input[1]=component[3];
            return component[4]->output();
        }
    private :
        Gate *component[5] ;
} ;

class Adder
{
    public :
        virtual void setValue(bool, int) = 0 ;
        virtual void setValue(Gate *, int) = 0 ;
        virtual Gate *sum() = 0 ;
        virtual Gate *sum(int n)=0;
        virtual Gate *carryOut() = 0 ;
} ;

class OneBitHalfAdder : public Adder
{
    public :
        OneBitHalfAdder() {
            component[0]=new XOR;
            component[1]=new AND;
        }
        virtual void setValue(bool val, int pin) {
            component[0]->setValue(val,pin);
            component[1]->setValue(val,pin);
        }
        virtual void setValue(Gate *gate, int pin) {
            component[0]->setValue(gate,pin);
            component[1]->setValue(gate,pin);
        }
        virtual Gate *sum() {
            return component[0];
        }
        virtual Gate *sum(int n){
            Gate *gate;
            return gate;
        }
        virtual Gate *carryOut() {
            return component[1];
        }
    private :
        Gate *component[2] ;
} ;

class OneBitFullAdder : public Adder
{
    public :
        OneBitFullAdder() {
            a[0]=new OneBitHalfAdder;
            a[1]=new OneBitHalfAdder;
            carry=new OR;
        }
        virtual void setValue(bool val, int pin) {
            if(pin<2){a[0]->setValue(val,pin);}
            else if(pin==2){a[1]->setValue(val,1);}
        }
        virtual void setValue(Gate *gate, int pin) {
            if(pin<2){a[0]->setValue(gate,pin);}
            else if(pin==2){a[1]->setValue(gate,1);}
        }
        virtual Gate *sum() {
            a[1]->setValue(a[0]->sum(),0);
            return a[1]->sum();
        }
        virtual Gate *sum(int n){
            Gate *gate;
            return gate;
        }
        virtual Gate *carryOut() {
            a[1]->setValue(a[0]->sum(),0);
            carry->setValue(a[1]->carryOut(),0);
            carry->setValue(a[0]->carryOut(),1);
            return carry;
        }
    private :
        Adder *a[2] ;
        Gate *carry ;
} ;

class FourBitsRippleAdder:public Adder
{
    public :
        FourBitsRippleAdder() {
            a[0]=new OneBitFullAdder;
            a[1]=new OneBitFullAdder;
            a[2]=new OneBitFullAdder;
            a[3]=new OneBitFullAdder;
        }
        virtual void setValue(bool val, int pin) {
            if(pin<2){a[0]->setValue(val,pin);}
            else if(pin>=2 && pin<4){a[1]->setValue(val,pin-2);}
            else if(pin>=4 && pin<6){a[2]->setValue(val,pin-4);}
            else if(pin>=6 && pin<8){a[3]->setValue(val,pin-6);}
            else if(pin==8){a[0]->setValue(val,2);}
        }
        virtual void setValue(Gate *gate, int pin) {
            if(pin<2){a[0]->setValue(gate,pin);}
            else if(pin>=2 && pin<4){a[1]->setValue(gate,pin-2);}
            else if(pin>=4 && pin<6){a[2]->setValue(gate,pin-4);}
            else if(pin>=6 && pin<8){a[3]->setValue(gate,pin-6);}
            else if(pin==8){a[0]->setValue(gate,2);}
        }
        virtual Gate *sum() {
            Gate *gate;
            return gate;
        }
        virtual Gate *sum(int n) {
            _out();
            return a[n]->sum();
        }
        virtual Gate *carryOut() {
            _out();
            return a[3]->carryOut();
        }
        private:
        Adder *a[4];
        void _out(){
            a[1]->setValue(a[0]->carryOut(),2);
            a[2]->setValue(a[1]->carryOut(),2);
            a[3]->setValue(a[2]->carryOut(),2);
        }
};

class Decoder
{
    public :
        virtual void setValue(bool, int) = 0 ;
        virtual void setValue(Gate *, int) = 0 ;
        virtual void setEnable(bool) = 0 ;
        virtual void setEnable(Gate *) = 0 ;
        virtual int output() = 0 ;
        virtual Gate *operator[](int) = 0 ;
    protected :
        Gate *enable ;
} ;

class Decoder2_4 : public Decoder
{
    public :
        Decoder2_4() : Decoder2_4(0) {}
        Decoder2_4(bool val)
        {
            if(val) this -> enable = &t ;
            else this -> enable = &f ;
            for(int i = 0 ; i < 2 ; i++)
                component[i] = new NOT ;
            for(int i = 2 ; i < 6 ; i++)
                component[i] = new AND ;
            for(int i = 0 ; i < 4 ; i++)
                enables[i] = new AND ;
        }
        virtual void setEnable(bool val)
        {
            if(val) this -> enable = &t ;
            else this -> enable = &f ;
        }
        virtual void setEnable(Gate *gate) { this -> enable = gate ; }
        virtual void setValue(Gate *gate, int i) { component[i % 2] -> input[0] = gate ; }
        virtual void setValue(bool val, int i)
        {
            if(val) component[i % 2] -> input[0] = &t ;
            else component[i % 2] -> input[0] = &f ;
        }
        virtual Gate *operator[](int n)
        {
            _out() ;
            switch(n)
            {
                case 0 : return enables[0] ;
                case 1 : return enables[1] ;
                case 2 : return enables[2] ;
                case 3 : return enables[3] ;
                default : return nullptr ;
            }
        }
        friend ostream &operator<<(ostream &out, Decoder2_4 dec)
        {
            dec._out();
            for(int i = 3 ; i >= 0 ; i--)
                out << dec[i] -> output() << " " ;
            return out ;
        }
        virtual int output()
        {
            _out();
            for(int i = 0 ; i < 4 ; i++)
                if(enables[i] -> output()) return i ;
            return -1;
        }
    private :
        Gate *component[6] ;
        Gate *enables[4] ;

        void _out()
        {
            component[2] -> input[0] = component[0] ;
            component[2] -> input[1] = component[1] ;

            component[3] -> input[0] = component[0] -> input[0] ;
            component[3] -> input[1] = component[1] ;

            component[4] -> input[0] = component[0] ;
            component[4] -> input[1] = component[1] -> input[0] ;

            component[5] -> input[0] = component[0] -> input[0] ;
            component[5] -> input[1] = component[1] -> input[0] ;

            for(int i = 0 ; i < 4 ; i++)
            {
                enables[i] -> input[0] = this -> enable ;
                enables[i] -> input[1] = component[i + 2] ;
            }
        }
} ;

class Decoder4_16 : public Decoder
{
    public :
        Decoder4_16() {
            dec2_4[0]=new Decoder2_4;
            dec2_4[1]=new Decoder2_4;
            dec2_4[2]=new Decoder2_4;
            dec2_4[3]=new Decoder2_4;
            dec2_4[4]=new Decoder2_4;
        }
        Decoder4_16(bool val):Decoder4_16() {
            dec2_4[0]->setEnable(val);
        }
        virtual void setEnable(bool val) {dec2_4[0]->setEnable(val);}
        virtual void setEnable(Gate *gate) {dec2_4[0]->setEnable(gate);}
        virtual void setValue(bool val, int pin) {
            if(pin<2){
                for(int i=1;i<5;i++){
                dec2_4[i]->setValue(val,pin);
                }
            }
            else if(pin==2 || pin==3){dec2_4[0]->setValue(val,pin-2);}
            else if(pin==4){dec2_4[0]->setEnable(val);}
        }
        virtual void setValue(Gate *gate, int pin) {
            if(pin<2){
                for(int i=1;i<5;i++){
                dec2_4[i]->setValue(gate,pin);
                }
            }
            else if(pin==2 || pin==3){dec2_4[0]->setValue(gate,pin-2);}
            else if(pin==4){dec2_4[0]->setEnable(gate);}
        }
        virtual Gate *operator[](int n) {
            _out();
            if(n<4){return (*dec2_4[1])[n];}
            else if(n>=4 && n<8){return (*dec2_4[2])[n-4];}
            else if(n>=8 && n<12){return (*dec2_4[3])[n-8];}
            else if(n>=12){return (*dec2_4[4])[n-12];}
            else return nullptr;
        }
        friend ostream &operator<<(ostream &out, Decoder4_16 &dec) {
            dec._out();
            for (int i = 4; i >=1; i--) {
                out << *(static_cast<Decoder2_4*>(dec.dec2_4[i]));
            }
            return out;
        }
        virtual int output() {
            _out();
            for (int i = 0; i < 16; ++i) {
                if ((*this)[i]->output())
                    return i;
            }
            return -1;
        }
    private :
        Decoder *dec2_4[5] ;
        void _out(){
            dec2_4[1]->setEnable((*dec2_4[0])[0]);
            dec2_4[2]->setEnable((*dec2_4[0])[1]);
            dec2_4[3]->setEnable((*dec2_4[0])[2]);
            dec2_4[4]->setEnable((*dec2_4[0])[3]);
        }
} ;

class Decoder5_32 : public Decoder
{
    public :
        Decoder5_32() {
            dec4_16[0]=new Decoder4_16;
            dec4_16[1]=new Decoder4_16;
            component=new NOT;
        }
        virtual void setValue(bool val, int pin) {
            if(pin<4){
                dec4_16[0]->setValue(val,pin);
                dec4_16[1]->setValue(val,pin);
            }
            else if(pin==4){
                component->setValue(val,0);
                dec4_16[1]->setEnable(val);
            }
        }
        virtual void setValue(Gate *gate, int pin) {
            if(pin<4){
                dec4_16[0]->setValue(gate,pin);
                dec4_16[1]->setValue(gate,pin);
            }
            else if(pin==4){
                component->setValue(gate,0);
                dec4_16[1]->setEnable(gate);
            }
        }
        virtual void setEnable(bool val) {dec4_16[0]->setEnable(val);}
        virtual void setEnable(Gate *gate) {dec4_16[0]->setEnable(gate);}
        virtual Gate *operator[](int n) {
            _out();
            if(n<16){return (*dec4_16[0])[n];}
            else if(n>=16){return (*dec4_16[1])[n-16];}
            else return nullptr;
        }
        friend ostream &operator<<(ostream &out, Decoder5_32 &dec) {
            dec._out();
            for (int i = 1; i >=0; i--) {
                out << *(static_cast<Decoder4_16*>(dec.dec4_16[i]));
            }
            return out;
        }
        virtual int output() {
            _out();
            for (int i = 0; i < 32; ++i) {
                if ((*this)[i]->output())
                    return i;
            }
            return -1;
        }
    private :
        Decoder *dec4_16[2];
        Gate *component;
        void _out(){
            dec4_16[0]->setEnable(component);
        }
} ;

class Sol{
    public:
        Sol(int a0,int a1,int a2,int a3,int b0,int b1,int b2,int b3){
            dec5_32=new Decoder5_32;
            a=new FourBitsRippleAdder;
            a->setValue(false,8);
            a->setValue(b0,7);
            a->setValue(a0,6);
            a->setValue(b1,5);
            a->setValue(a1,4);
            a->setValue(b2,3);
            a->setValue(a2,2);
            a->setValue(b3,1);
            a->setValue(a3,0);
        }
        friend ostream &operator <<(ostream &out, Sol &sol){
            sol._out();
            out<<*(static_cast<Decoder5_32*>(sol.dec5_32))<<endl;
            return out;
        }
        virtual int output(){
            _out();
            return dec5_32->output();
        }

    private:
        Decoder *dec5_32;
        Adder *a;
        void _out(){
            dec5_32->setValue(a->sum(0),0);
            dec5_32->setValue(a->sum(1),1);
            dec5_32->setValue(a->sum(2),2);
            dec5_32->setValue(a->sum(3),3);
            dec5_32->setValue(a->carryOut(),4);
            dec5_32->setEnable(1);
        }
};

int main() {

    int a0,a1,a2,a3,b0,b1,b2,b3;
    cin>>a0>>a1>>a2>>a3>>b0>>b1>>b2>>b3;

    Sol sol(a0,a1,a2,a3,b0,b1,b2,b3);
    
    cout<<sol<<sol.output();

}