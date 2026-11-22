; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_9 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(assert
 (let ((?x159 (bvmul arg0_6 arg0_9)))
(let ((?x33437 (bvmul (_ bv4294967295 32) ?x159)))
(let ((?x685 (bvmul arg0_6 arg0_6)))
(let ((?x22201 (bvadd ?x685 ?x33437)))
(and (distinct ?x22201 (_ bv0 32)) true))))))
(check-sat)
