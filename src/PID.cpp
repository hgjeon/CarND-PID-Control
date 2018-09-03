#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Kd = Kd;
  this->Ki = Ki;

  p_error = 0;
  d_error = 0;
  i_error = 0;
}

void PID::UpdateError(double cte) {
  d_error = cte - p_error;  // cte - cte_prev
  p_error = cte;            // cte
  i_error += cte;           // Accumulated cte
}

double PID::TotalError() {
  double error;

  error = Kp * p_error + Kd * d_error + Ki * i_error;
  return error;
}
