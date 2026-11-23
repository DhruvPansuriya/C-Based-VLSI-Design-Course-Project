; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_21 () (_ BitVec 32))
(declare-fun arg0_21 () (_ BitVec 32))
(declare-fun arg1_42 () (_ BitVec 32))
(assert
 (let ((?x72917 (bvmul arg0_21 arg1_21)))
(let ((?x59144 (bvmul (_ bv4294967295 32) ?x72917)))
(let ((?x63645 (bvmul arg0_21 arg1_42)))
(let ((?x70006 (bvadd ?x63645 ?x59144)))
(and (distinct ?x70006 (_ bv0 32)) true))))))
(check-sat)
