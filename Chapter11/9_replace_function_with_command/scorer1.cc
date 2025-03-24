#include <iostream>
#include <memory>

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

class Scorer {
 public:
  Scorer(Candidate candidate, MedicalExam medical_exam,
         ScoringGuide scoring_guide)
      : candidate_(candidate),
        medical_exam_(medical_exam),
        scoring_guide_(scoring_guide) {}

  int excute() {
    result_ = 0;
    health_level_ = 0;
    high_medical_risk_flag_ = false;

    ScoreSmoking();
    std::string certification_grade = "regular";
    if (scoring_guide_.StateWithLowCertification(candidate_.origin_state)) {
      certification_grade = "low";
      result_ -= 5;
    }

    /* lots of code like this */
    result_ -= std::max(health_level_ - 5, 0);
    return result_;
  }

 private:
  void ScoreSmoking() {
    if (medical_exam_.is_smoker) {
      health_level_ += 10;
      high_medical_risk_flag_ = true;
    }
  }

  Candidate candidate_;
  MedicalExam medical_exam_;
  ScoringGuide scoring_guide_;

  int result_;
  int health_level_;
  bool high_medical_risk_flag_;
};

int main() {
  Candidate candidate(6);
  MedicalExam medical_exam(true);
  ScoringGuide scoring_guide;

  std::cout << Scorer(candidate, medical_exam, scoring_guide).excute()
            << std::endl;
  return 0;
}