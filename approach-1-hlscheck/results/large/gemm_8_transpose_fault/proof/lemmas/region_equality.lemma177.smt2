; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_10 () (_ BitVec 32))
(declare-fun arg0_26 () (_ BitVec 32))
(declare-fun arg1_17 () (_ BitVec 32))
(assert
 (let ((?x63959 (bvmul arg0_26 arg1_10)))
(let ((?x53837 (bvmul (_ bv4294967295 32) ?x63959)))
(let ((?x64067 (bvmul arg0_26 arg1_17)))
(let ((?x67310 (bvadd ?x64067 ?x53837)))
(and (distinct ?x67310 (_ bv0 32)) true))))))
(check-sat)
