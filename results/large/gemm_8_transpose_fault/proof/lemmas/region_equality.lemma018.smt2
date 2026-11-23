; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_20 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(declare-fun arg1_34 () (_ BitVec 32))
(assert
 (let ((?x73079 (bvmul arg0_4 arg1_20)))
(let ((?x23543 (bvmul (_ bv4294967295 32) ?x73079)))
(let ((?x63358 (bvmul arg0_4 arg1_34)))
(let ((?x55188 (bvadd ?x63358 ?x23543)))
(and (distinct ?x55188 (_ bv0 32)) true))))))
(check-sat)
