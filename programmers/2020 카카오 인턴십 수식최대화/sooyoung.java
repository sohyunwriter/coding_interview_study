package com.syleemk.algorithm;

import java.util.ArrayList;

public class KakaoOpMax {
    char[] oper = {'+', '-', '*'};
    boolean[] visited = new boolean[3];
    ArrayList<Long> numbers = new ArrayList<>();
    ArrayList<Character> opers = new ArrayList<>();
    long answer;

    public static void main(String[] args) {
        String expression = "100-200*300-500+20";
        KakaoOpMax test = new KakaoOpMax();
        long solution = test.solution(expression);
        System.out.println("solution = " + solution);
    }

    public long solution(String expression) {

        String number = "";
        for (int i = 0; i < expression.length(); i++) {
            if (expression.charAt(i) >= '0' && expression.charAt(i) <= '9') {
                number += expression.charAt(i);
            } else {
                numbers.add(Long.parseLong(number));
                opers.add(expression.charAt(i));
                number = "";
            }
        }
        numbers.add(Long.parseLong(number));

        dfs(0, new char[3]);

        return answer;
    }

    public void dfs(int count, char[] p) {

        if (count == 3) {
            ArrayList<Long> copyNumbers = new ArrayList<>(numbers);
            ArrayList<Character> copyOpers = new ArrayList<>(opers);
            System.out.println(copyNumbers.size() + " " + copyOpers.size());
            for (int i = 0; i < p.length; i++) {
                for (int j = 0; j < copyOpers.size(); j++) {
                    if (copyOpers.get(j) == p[i]) {
                        Long result = cal(copyNumbers.remove(j), copyNumbers.remove(j), p[i]);
                        copyNumbers.add(j, result);
                        copyOpers.remove(j);
                        j--;
                    }
                }
            }
            answer = Math.max(answer, Math.abs(copyNumbers.get(0)));
            return;
        }

        //우선순위 정하는 부분
        for (int i = 0; i < 3; i++) {
            if (!visited[i]) {
                visited[i]= true;
                p[count] = oper[i];
                dfs(count + 1, p);
                visited[i] = false;
            }
        }
    }

    public Long cal(Long num1, Long num2, char op) {
        if (op == '+') {
            return num1 + num2;
        } else if (op == '*') {
            return num1 * num2;
        } else {
            return num1 - num2;
        }
    }
}
