; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_52 () (_ BitVec 32))
(declare-fun arg0_20 () (_ BitVec 32))
(declare-fun arg1_38 () (_ BitVec 32))
(assert
 (let ((?x75203 (bvmul arg0_20 arg1_52)))
(let ((?x61652 (bvmul (_ bv4294967295 32) ?x75203)))
(let ((?x64069 (bvmul arg0_20 arg1_38)))
(let ((?x66494 (bvadd ?x64069 ?x61652)))
(and (distinct ?x66494 (_ bv0 32)) true))))))
(check-sat)
