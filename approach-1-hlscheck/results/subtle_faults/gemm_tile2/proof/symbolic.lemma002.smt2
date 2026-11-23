; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_4 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(declare-fun arg1_5 () (_ BitVec 32))
(assert
 (let ((?x735539 (bvmul arg0_1 arg1_4)))
(let ((?x46183 (bvmul (_ bv4294967295 32) ?x735539)))
(let ((?x505018 (bvmul arg0_1 arg1_5)))
(let ((?x538866 (bvadd ?x505018 ?x46183)))
(and (distinct ?x538866 (_ bv0 32)) true))))))
(check-sat)
