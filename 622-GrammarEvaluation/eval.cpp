float evalExpression()
{
    float term_value = evalTerm();
    read_next();
    if "+" then
        read_next();
        return evalExpression() + term_value;         E -> E + T
    else if "-" then
        read_next();
        return evalExpression() - term_value;          E -> E - T
    else
        return term_value;                                       E -> T
}

float evalTerm()
    factor_value = evalFactor();
    read_next();
    if "*" then
        read_next();
        return evalFactor() * factor_value;              T -> T * F
    else if "/" then
        read_next();
        return evalFactor() / factor_value;               T -> T / F
    else
        return factor_value;                                     T -> F
float evalFactor()
    if number then
        return number;                                            F -> n
    else if ")" then
        read_next();
        number_value = evalExpression();
        if "(" then
            read_next();
            return number_value;                              F -> (E)
        else
            print "syntax error!";