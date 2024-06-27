// A. Drinks Choosing

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Old timers of Summer Informatics School can remember previous camps in which each student was given a drink of his choice on the vechorka (late-evening meal). Or may be the story was more complicated? There are n students living in a building, and for each of them the favorite drink ai is known. So you know n integers a1,a2,…,an, where ai (1≤ai≤k) is the type of the favorite drink of the i-th student. The drink types are numbered from 1 to k. There are infinite number of drink sets. Each set consists of exactly two portions of the same drink. In other words, there are k types of drink sets, the j-th type contains two portions of the drink j. The available number of sets of each of the k types is infinite. You know that students will receive the minimum possible number of sets to give all students exactly one drink. Obviously, the number of sets will be exactly ⌈n2⌉, where ⌈x⌉ is x rounded up. After students receive the sets, they will distribute their portions by their choice: each student will get exactly one portion. Note, that if n is odd then one portion will remain unused and the students' teacher will drink it. What is the maximum number of students that can get their favorite drink if ⌈n2⌉ sets will be chosen optimally and students will distribute portions between themselves optimally?

// Input
// The first line of the input contains two integers n and k (1≤n,k≤1000) — the number of students in the building and the number of different drinks. The next n lines contain student's favorite drinks. The i-th line contains a single integer from 1 to k — the type of the favorite drink of the i-th student.

// Output
// Print exactly one integer — the maximum number of students that can get a favorite drink.

// Examples
// inputCopy
// 5 3
// 1
// 3
// 1
// 1
// 2
// outputCopy
// 4
// inputCopy
// 10 3
// 2
// 1
// 3
// 2
// 3
// 3
// 1
// 3
// 1
// 2
// outputCopy
// 9

// Note

// In the first example, students could choose three sets with drinks 1, 1 and 2 (so they will have two sets with two drinks of the type 1 each and one set with two drinks of the type 2, so portions will be 1,1,1,1,2,2). This way all students except the second one will get their favorite drinks.
// Another possible answer is sets with drinks 1, 2 and 3. In this case the portions will be 1,1,2,2,3,3. Then all the students except one will gain their favorite drinks. The only student that will not gain the favorite drink will be a student with ai=1 (i.e. the first, the third or the fourth).

