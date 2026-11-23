; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_4 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg1_32 () (_ BitVec 32))
(assert
 (let ((?x63852 (bvmul arg0_12 arg1_4)))
(let ((?x68271 (bvmul (_ bv4294967295 32) ?x63852)))
(let ((?x64055 (bvmul arg0_12 arg1_32)))
(let ((?x74682 (bvadd ?x64055 ?x68271)))
(and (distinct ?x74682 (_ bv0 32)) true))))))
(check-sat)
