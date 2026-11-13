; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_44 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(declare-fun arg1_37 () (_ BitVec 32))
(assert
 (let ((?x73288 (bvmul arg0_4 arg1_44)))
(let ((?x58849 (bvmul (_ bv4294967295 32) ?x73288)))
(let ((?x63577 (bvmul arg0_4 arg1_37)))
(let ((?x67528 (bvadd ?x63577 ?x58849)))
(and (distinct ?x67528 (_ bv0 32)) true))))))
(check-sat)
