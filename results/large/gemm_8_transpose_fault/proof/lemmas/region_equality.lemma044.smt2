; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_49 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(declare-fun arg1_14 () (_ BitVec 32))
(assert
 (let ((?x26583 (bvmul arg0_1 arg1_49)))
(let ((?x55033 (bvmul (_ bv4294967295 32) ?x26583)))
(let ((?x63578 (bvmul arg0_1 arg1_14)))
(let ((?x64171 (bvadd ?x63578 ?x55033)))
(and (distinct ?x64171 (_ bv0 32)) true))))))
(check-sat)
