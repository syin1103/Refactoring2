#include <iostream>

struct Candidate {
  Candidate(int state) : origin_state(state) {}
  int origin_state;
};

struct MedicalExam {
  MedicalExam(bool flag) : is_smoker(flag) {}
  bool is_smoker;
};

struct ScoringGuide {
  bool StateWithLowCertification(int origin_state) { return true; }
};

int Score(Candidate candidate, MedicalExam medical_exam,
          ScoringGuide scoring_guide) {
  int result = 0;
  int health_level = 0;
  bool high_medical_risk_flag = false;

  if (medical_exam.is_smoker) {
    health_level += 10;
    high_medical_risk_flag = true;
  }

  std::string certification_grade = "regular";
  if (scoring_guide.StateWithLowCertification(candidate.origin_state)) {
    certification_grade = "low";
    result -= 5;
  }

  /* lots of code like this */
  result -= std::max(health_level - 5, 0);
  return result;
}

int main() {
  Candidate candidate(6);
  MedicalExam medical_exam(true);
  ScoringGuide scoring_guide;

  std::cout << Score(candidate, medical_exam, scoring_guide) << std::endl;
  return 0;
}