#include "PID.h"
#include <limits>
using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	this->Kp = Kp; // proportional coefficient
 	this->Ki = Ki; // integral coefficient
  	this->Kd = Kd; // differential coefficient

  	i_error = 0.0; // integral cte
  	p_error = numeric_limits<double>::max(); // previous cte
  	d_error = 0.0; // differential cte
}

void PID::UpdateError(double cte) {
	// first time through make the previous error equal to cte
  	if (p_error == numeric_limits<double>::max())
  		p_error = cte;

  	d_error = cte - p_error;
  	p_error = cte;
  	i_error += cte;
}

double PID::TotalError() {
	return -Kp * p_error - Kd * d_error - Ki * i_error;
}

void PID::Twiddle(){
    // twiddle algorithm - not used currently.
    double dp[] = {1., 1., 1.};
    double p[] = {0., 0., 0.};
    double arrsum = 3.;
    double tol = 0.001;
    double cur_err = 0.;
    best_err = this->TotalError();
    cur_err = 0.;
    while (arrsum > tol){
        for (int i=0; i < 3;i++){
            p[i] += dp[i];
            this->UpdateCoefs(p);
            cur_err = this->TotalError();

            if (cur_err < best_err){
                best_err = cur_err;
                dp[i] *= 1.1;
            }else{
                p[i] -= 2. * dp[i];
                this->UpdateCoefs(p);
                cur_err = this->TotalError();

                if (cur_err < best_err){
                    best_err = cur_err;
                    dp[i] *= 1.1;
                }else{
                    p[i] += dp[i];
                    dp[i] *= 0.9;
                    this->UpdateCoefs(p);
                }

            }
        }
        arrsum = 0.;
        for (int i = 0; i < 3; i++){
            arrsum += dp[i];
        }
    }

}

void PID::UpdateCoefs(double updates[]){
    // update coefficients for pid - not currently used
    Kp = updates[0];
    Kd = updates[1];
    Ki = updates[2];
}

