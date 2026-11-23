; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_12 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg1_33 () (_ BitVec 32))
(assert
 (let ((?x75258 (bvmul arg0_12 arg1_12)))
(let ((?x71226 (bvmul (_ bv4294967295 32) ?x75258)))
(let ((?x11892 (bvmul arg0_12 arg1_33)))
(let ((?x69266 (bvadd ?x11892 ?x71226)))
(and (distinct ?x69266 (_ bv0 32)) true))))))
(check-sat)
