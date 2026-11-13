; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_50 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg1_22 () (_ BitVec 32))
(assert
 (let ((?x22030 (bvmul arg0_2 arg1_50)))
(let ((?x69922 (bvmul (_ bv4294967295 32) ?x22030)))
(let ((?x9877 (bvmul arg0_2 arg1_22)))
(let ((?x53981 (bvadd ?x9877 ?x69922)))
(and (distinct ?x53981 (_ bv0 32)) true))))))
(check-sat)
